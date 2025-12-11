#include <stdio.h>
#include "../include/quarto.h"


// -----------------------------------------------------------
// Verifica se já existe um quarto com o mesmo número (OK)
// -----------------------------------------------------------
int quarto_existe(int numero) {
    FILE *f = fopen(ARQ_QUARTOS, "rb");
    if (!f) return 0;

    Quarto q;

    while (fread(&q, sizeof(Quarto), 1, f) == 1) {
        if (q.numero == numero) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Salvar quarto garantindo número único (OK)
// -----------------------------------------------------------
int quarto_salvar(Quarto novo) {

    if (quarto_existe(novo.numero)) {
        printf("\nErro: Já existe um quarto com esse número.\n");
        return 0;
    }

    FILE *f = fopen(ARQ_QUARTOS, "ab");
    if (!f) return 0;

    fwrite(&novo, sizeof(Quarto), 1, f);
    fclose(f);

    return 1;
}


// -----------------------------------------------------------
// Listar quartos (OK)
// -----------------------------------------------------------
int quarto_listar(void) {
    FILE *f = fopen(ARQ_QUARTOS, "rb");
    if (!f) {
        printf("\nNenhum quarto cadastrado.\n");
        return 0;
    }

    Quarto q;

    printf("\n===== LISTA DE QUARTOS =====\n");
    while (fread(&q, sizeof(Quarto), 1, f) == 1) {
        printf("Número      : %d\n", q.numero);
        printf("Capacidade  : %d\n", q.capacidade);
        printf("Valor diária: %.2f\n", q.valor_diaria);
        printf("Status      : %s\n", q.ocupado ? "Ocupado" : "Desocupado");
        printf("-------------------------------------\n");
    }

    fclose(f);
    return 1;
}


// -----------------------------------------------------------
// Buscar quarto (OK)
// -----------------------------------------------------------
int quarto_buscar(int numero, Quarto *out) {
    FILE *f = fopen(ARQ_QUARTOS, "rb");
    if (!f) return 0;

    Quarto q;

    while (fread(&q, sizeof(Quarto), 1, f) == 1) {
        if (q.numero == numero) {
            *out = q;
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}



// ===========================================================
// ⬇️ FUNÇÕES NOVAS — NECESSÁRIAS PARA AS ESTADIAS
// ===========================================================


// -----------------------------------------------------------
// Atualiza status do quarto (0 = livre, 1 = ocupado)
// -----------------------------------------------------------
int quarto_atualizar_status(int numero, int novo_status) {
    FILE *f = fopen(ARQ_QUARTOS, "rb+");
    if (!f) return 0;

    Quarto q;

    while (fread(&q, sizeof(Quarto), 1, f) == 1) {
        if (q.numero == numero) {

            q.ocupado = novo_status;

            fseek(f, -sizeof(Quarto), SEEK_CUR);
            fwrite(&q, sizeof(Quarto), 1, f);
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Marca quarto como OCUPADO
// -----------------------------------------------------------
int quarto_ocupar(int numero) {
    return quarto_atualizar_status(numero, 1);
}


// -----------------------------------------------------------
// Marca quarto como DESOCUPADO
// -----------------------------------------------------------
int quarto_desocupar(int numero) {
    return quarto_atualizar_status(numero, 0);
}
