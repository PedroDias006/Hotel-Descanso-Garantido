#ifndef CLIENTE_H
#define CLIENTE_H

#define ARQ_CLIENTES "data/clientes.dat"

typedef struct {
    int codigo;
    char nome[80];
    char telefone[20];
    char endereco[120];


    int pontos;
} Cliente;

int cliente_gerar_codigo(void);
int cliente_salvar(Cliente novo);
int cliente_listar(void);
int cliente_buscar_por_codigo(int codigo, Cliente *resultado);
int cliente_buscar_por_nome(const char *nome, Cliente *resultado);


int cliente_atualizar(Cliente c);
int cliente_somar_pontos(int codigo_cliente, int pontos);

#endif
