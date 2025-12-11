#include <stdio.h>
#include <string.h>
#include "../include/cliente.h"


// -----------------------------------------------------------
// Verifica se o código já existe
// -----------------------------------------------------------
int cliente_codigo_existe(int codigo) {
    FILE *f = fopen(ARQ_CLIENTES, "rb");
    if (!f) return 0;

    Cliente c;
    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        if (c.codigo == codigo) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Geração automática de código sequencial
// -----------------------------------------------------------
int cliente_gerar_codigo(void) {
    FILE *f = fopen(ARQ_CLIENTES, "rb");
    if (!f) return 1;

    Cliente c;
    int maior = 0;

    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        if (c.codigo > maior) maior = c.codigo;
    }

    fclose(f);
    return maior + 1;
}


// -----------------------------------------------------------
// Salvar cliente NOVO
// -----------------------------------------------------------
int cliente_salvar(Cliente novo) {

    if (cliente_codigo_existe(novo.codigo)) {
        printf("\nErro: Já existe um cliente com o código %d.\n", novo.codigo);
        return 0;
    }

    // Sempre começa com 0 pontos
    novo.pontos = 0;

    FILE *f = fopen(ARQ_CLIENTES, "ab");
    if (!f) return 0;

    fwrite(&novo, sizeof(Cliente), 1, f);
    fclose(f);
    return 1;
}


// -----------------------------------------------------------
// Buscar cliente por código
// -----------------------------------------------------------
int cliente_buscar_por_codigo(int codigo, Cliente *resultado) {
    FILE *f = fopen(ARQ_CLIENTES, "rb");
    if (!f) return 0;

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        if (c.codigo == codigo) {
            *resultado = c;
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Buscar cliente por nome
// -----------------------------------------------------------
int cliente_buscar_por_nome(const char *nome, Cliente *resultado) {
    FILE *f = fopen(ARQ_CLIENTES, "rb");
    if (!f) return 0;

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        if (strstr(c.nome, nome) != NULL) {
            *resultado = c;
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Atualizar cliente no arquivo (necessário para pontos)
// -----------------------------------------------------------
int cliente_atualizar(Cliente cAtualizado) {
    FILE *f = fopen(ARQ_CLIENTES, "rb+");
    if (!f) return 0;

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        if (c.codigo == cAtualizado.codigo) {

            fseek(f, -sizeof(Cliente), SEEK_CUR);
            fwrite(&cAtualizado, sizeof(Cliente), 1, f);
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Somar pontos de fidelidade ao cliente
// -----------------------------------------------------------
int cliente_somar_pontos(int codigo_cliente, int pontos) {

    Cliente c;

    if (!cliente_buscar_por_codigo(codigo_cliente, &c)) {
        printf("\nErro: cliente não encontrado para somar pontos.\n");
        return 0;
    }

    c.pontos += pontos;

    return cliente_atualizar(c);
}


// -----------------------------------------------------------
// Listar clientes (agora mostra pontos)
// -----------------------------------------------------------
int cliente_listar(void) {
    FILE *f = fopen(ARQ_CLIENTES, "rb");
    if (!f) {
        printf("\nNenhum cliente cadastrado ainda.\n");
        return 0;
    }

    Cliente c;
    printf("\n--- Lista de Clientes ---\n");

    while (fread(&c, sizeof(Cliente), 1, f) == 1) {
        printf("Código   : %d\n", c.codigo);
        printf("Nome     : %s\n", c.nome);
        printf("Telefone : %s\n", c.telefone);
        printf("Endereço : %s\n", c.endereco);
        printf("Pontos   : %d\n\n", c.pontos);
    }

    fclose(f);
    return 1;
}
