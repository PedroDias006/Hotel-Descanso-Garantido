#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/estadia.h"
#include "../include/quarto.h"
#include "../include/cliente.h"


// ======================================================================
// GERAÇÃO DE CÓDIGO AUTOMÁTICO
// ======================================================================
int gerar_codigo_estadia() {
    FILE *f = fopen(ARQ_ESTADIAS, "rb");
    if (!f) return 1;

    Estadia e;
    int maior = 0;

    while (fread(&e, sizeof(Estadia), 1, f) == 1) {
        if (e.codigo_estadia > maior)
            maior = e.codigo_estadia;
    }

    fclose(f);
    return maior + 1;
}


// ======================================================================
// VALIDAÇÃO DE DATAS
// ======================================================================
int validar_datas(
    int d1, int m1, int a1,
    int d2, int m2, int a2
) {
    int entrada = a1*365 + m1*30 + d1;
    int saida   = a2*365 + m2*30 + d2;
    return saida > entrada;
}


// ======================================================================
// CÁLCULO DE DIÁRIAS
// ======================================================================
int calcular_diarias(int d1, int m1, int a1, int d2, int m2, int a2) {
    int entrada = a1*365 + m1*30 + d1;
    int saida   = a2*365 + m2*30 + d2;

    if (saida <= entrada) return 0;
    return saida - entrada;
}


// ======================================================================
// VERIFICA CONFLITO DE DATAS NO MESMO QUARTO
// ======================================================================
int quarto_ocupado_no_periodo(int numero_quarto, Estadia nova) {
    FILE *f = fopen(ARQ_ESTADIAS, "rb");
    if (!f) return 0;

    Estadia e;

    int entrada_nova = nova.ano_entrada*365 + nova.mes_entrada*30 + nova.dia_entrada;
    int saida_nova   = nova.ano_saida*365   + nova.mes_saida*30   + nova.dia_saida;

    while (fread(&e, sizeof(Estadia), 1, f) == 1) {

        if (e.numero_quarto != numero_quarto) continue;
        if (!e.ativa) continue;

        int entrada_e = e.ano_entrada*365 + e.mes_entrada*30 + e.dia_entrada;
        int saida_e   = e.ano_saida*365   + e.mes_saida*30   + e.dia_saida;

        if (!(saida_nova <= entrada_e || entrada_nova >= saida_e)) {
            fclose(f);
            return 1; // conflito
        }
    }

    fclose(f);
    return 0;
}


// ======================================================================
// REGISTRO DE ESTADIA (CORRIGIDO E COMPLETO)
// ======================================================================
int registrar_estadia(Estadia nova) {

    // 1. Valida se o quarto tem capacidade suficiente
    Quarto q;
    if (!quarto_buscar(nova.numero_quarto, &q)) {
        return 0;
    }

    if (nova.qtd_hospedes > q.capacidade) {
        printf("\nErro: O quarto suporta no máximo %d hóspedes.\n", q.capacidade);
        return 0;
    }

    // 2. Marca o quarto como ocupado
    quarto_ocupar(nova.numero_quarto);

    // 3. Salva a estadia
    FILE *f = fopen(ARQ_ESTADIAS, "ab");
    if (!f) return 0;

    fwrite(&nova, sizeof(Estadia), 1, f);
    fclose(f);

    return 1;
}


// ======================================================================
// BAIXA DE ESTADIA (NOVO — COMPLETO)
// ======================================================================
int baixa_estadia(int codigo_estadia) {

    FILE *f = fopen(ARQ_ESTADIAS, "rb+");
    if (!f) {
        printf("\nNenhuma estadia encontrada.\n");
        return 0;
    }

    Estadia e;
    int achou = 0;

    while (fread(&e, sizeof(Estadia), 1, f) == 1) {

        if (e.codigo_estadia == codigo_estadia && e.ativa == 1) {

            achou = 1;

            // 1. Calcular valor total
            Quarto q;
            if (!quarto_buscar(e.numero_quarto, &q)) {
                printf("\nErro: quarto da estadia não encontrado.\n");
                fclose(f);
                return 0;
            }

            float total = e.qtd_diarias * q.valor_diaria;

            // 2. Desocupar quarto
            quarto_desocupar(e.numero_quarto);

            // 3. Finalizar estadia
            e.ativa = 0;

            fseek(f, -sizeof(Estadia), SEEK_CUR);
            fwrite(&e, sizeof(Estadia), 1, f);

            fclose(f);

            printf("\n=== BAIXA REALIZADA ===\n");
            printf("Estadia: %d\n", codigo_estadia);
            printf("Quarto: %d\n", e.numero_quarto);
            printf("Diárias: %d\n", e.qtd_diarias);
            printf("Valor total: R$ %.2f\n", total);

            return 1;
        }
    }

    fclose(f);

    if (!achou) {
        printf("\nNenhuma estadia ativa com esse código.\n");
    }

    return 0;
}


// ======================================================================
// LISTAR TODAS AS ESTADIAS
// ======================================================================
int listar_estadias() {
    FILE *f = fopen(ARQ_ESTADIAS, "rb");
    if (!f) {
        printf("\nNenhuma estadia registrada.\n");
        return 0;
    }

    Estadia e;

    printf("\n===== LISTA DE ESTADIAS =====\n");

    while (fread(&e, sizeof(Estadia), 1, f) == 1) {

        printf("Estadia %d | Cliente %d | Quarto %d\n",
               e.codigo_estadia, e.codigo_cliente, e.numero_quarto);

        printf("Entrada: %02d/%02d/%04d\n", e.dia_entrada, e.mes_entrada, e.ano_entrada);
        printf("Saída  : %02d/%02d/%04d\n", e.dia_saida,   e.mes_saida,   e.ano_saida);

        printf("Diárias: %d\n", e.qtd_diarias);
        printf("Status: %s\n", e.ativa ? "ATIVA" : "FINALIZADA");

        printf("-----------------------------------\n");
    }

    fclose(f);
    return 1;
}


// ======================================================================
// LISTAR ESTADIAS POR CLIENTE (NOVO)
// ======================================================================
int listar_estadias_por_cliente(int codigo) {

    FILE *f = fopen(ARQ_ESTADIAS, "rb");
    if (!f) {
        printf("\nNenhuma estadia registrada.\n");
        return 0;
    }

    Estadia e;
    int encontrou = 0;

    printf("\n===== ESTADIAS DO CLIENTE %d =====\n", codigo);

    while (fread(&e, sizeof(Estadia), 1, f) == 1) {

        if (e.codigo_cliente == codigo) {

            encontrou = 1;

            printf("Estadia: %d\n", e.codigo_estadia);
            printf("Quarto : %d\n", e.numero_quarto);
            printf("Entrada: %02d/%02d/%04d\n", e.dia_entrada, e.mes_entrada, e.ano_entrada);
            printf("Saída  : %02d/%02d/%04d\n", e.dia_saida,   e.mes_saida,   e.ano_saida);
            printf("Diárias: %d\n", e.qtd_diarias);
            printf("Status : %s\n", e.ativa ? "ATIVA" : "FINALIZADA");
            printf("-----------------------------------\n");
        }
    }

    fclose(f);

    if (!encontrou) {
        printf("\nNenhuma estadia encontrada para este cliente.\n");
    }

    return encontrou;
}
