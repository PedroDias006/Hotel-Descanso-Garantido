#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#define ARQ_FUNCIONARIOS "data/funcionarios.dat"

typedef struct {
    int codigo;
    char nome[80];
    char telefone[20];
    char cargo[40];
    float salario;
} Funcionario;

int funcionario_gerar_codigo(void);
int funcionario_salvar(Funcionario novo);
int funcionario_listar(void);
int funcionario_buscar_por_codigo(int codigo, Funcionario *out);
int funcionario_buscar_por_nome(const char *nome, Funcionario *out);

#endif
