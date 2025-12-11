#ifndef ESTADIA_H
#define ESTADIA_H

#include "cliente.h"
#include "quarto.h"

#define ARQ_ESTADIAS "data/estadia.dat"

typedef struct {
    int codigo_estadia;
    int codigo_cliente;
    int numero_quarto;

    int dia_entrada, mes_entrada, ano_entrada;
    int dia_saida,   mes_saida,   ano_saida;

    int qtd_diarias;
    int qtd_hospedes;

    int ativa;
} Estadia;

int gerar_codigo_estadia();
int validar_datas(int d1, int m1, int a1, int d2, int m2, int a2);
int calcular_diarias(int d1, int m1, int a1, int d2, int m2, int a2);
int quarto_ocupado_no_periodo(int numero_quarto, Estadia nova);

int registrar_estadia(Estadia nova);
int baixa_estadia(int codigo);

int listar_estadias();
int listar_estadias_por_cliente(int codigo);

#endif
