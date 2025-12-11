#include <stdio.h>
#include <string.h>
#include "../include/funcionario.h"


// -----------------------------------------------------------
// Função interna: verifica se existe funcionário com o mesmo código
// -----------------------------------------------------------
int funcionario_codigo_existe(int codigo) {
    FILE *f = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!f) return 0;

    Funcionario ftemp;

    while (fread(&ftemp, sizeof(Funcionario), 1, f) == 1) {
        if (ftemp.codigo == codigo) {
            fclose(f);
            return 1; // Já existe funcionário com esse código
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Geração automática de código sequencial (OK)
// -----------------------------------------------------------
int funcionario_gerar_codigo(void) {
    FILE *f = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!f) return 1;

    Funcionario ftemp;
    int maior = 0;

    while (fread(&ftemp, sizeof(Funcionario), 1, f) == 1) {
        if (ftemp.codigo > maior)
            maior = ftemp.codigo;
    }

    fclose(f);
    return maior + 1;
}


// -----------------------------------------------------------
// Salvar funcionário COM validações:
// - impedir código duplicado
// - salário deve ser maior que zero
// -----------------------------------------------------------
int funcionario_salvar(Funcionario novo) {

    // 🔥 Regra obrigatória: código não pode repetir
    if (funcionario_codigo_existe(novo.codigo)) {
        printf("\nErro: Já existe um funcionário com o código %d.\n", novo.codigo);
        return 0;
    }

    // 🔥 Regra obrigatória: salário válido
    if (novo.salario <= 0) {
        printf("\nErro: Salário inválido. Deve ser maior que zero.\n");
        return 0;
    }

    FILE *f = fopen(ARQ_FUNCIONARIOS, "ab");
    if (!f) return 0;

    fwrite(&novo, sizeof(Funcionario), 1, f);
    fclose(f);

    return 1;
}


// -----------------------------------------------------------
// Listar funcionários (OK)
// -----------------------------------------------------------
int funcionario_listar(void) {
    FILE *f = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!f) {
        printf("\nNenhum funcionário cadastrado.\n");
        return 0;
    }

    Funcionario ftemp;
    printf("\n==== FUNCIONÁRIOS CADASTRADOS ====\n");

    while (fread(&ftemp, sizeof(Funcionario), 1, f) == 1) {
        printf("Código   : %d\n", ftemp.codigo);
        printf("Nome     : %s\n", ftemp.nome);
        printf("Telefone : %s\n", ftemp.telefone);
        printf("Cargo    : %s\n", ftemp.cargo);
        printf("Salário  : %.2f\n", ftemp.salario);
        printf("-----------------------------------\n");
    }

    fclose(f);
    return 1;
}


// -----------------------------------------------------------
// Buscar por código (OK)
// -----------------------------------------------------------
int funcionario_buscar_por_codigo(int codigo, Funcionario *out) {
    FILE *f = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!f) return 0;

    Funcionario ftemp;

    while (fread(&ftemp, sizeof(Funcionario), 1, f) == 1) {
        if (ftemp.codigo == codigo) {
            *out = ftemp;
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


// -----------------------------------------------------------
// Buscar por nome (OK)
// -----------------------------------------------------------
int funcionario_buscar_por_nome(const char *nome, Funcionario *out) {
    FILE *f = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!f) return 0;

    Funcionario ftemp;

    while (fread(&ftemp, sizeof(Funcionario), 1, f) == 1) {
        if (strstr(ftemp.nome, nome) != NULL) {
            *out = ftemp;
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
