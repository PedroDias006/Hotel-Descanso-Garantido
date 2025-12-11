#ifndef QUARTO_H
#define QUARTO_H

#define ARQ_QUARTOS "data/quartos.dat"

typedef struct {
    int numero;
    int capacidade;
    float valor_diaria;
    int ocupado; 
} Quarto;

int quarto_existe(int numero);
int quarto_salvar(Quarto novo);
int quarto_listar(void);
int quarto_buscar(int numero, Quarto *out);

// NOVAS FUNÇÕES
int quarto_atualizar_status(int numero, int status);
int quarto_ocupar(int numero);
int quarto_desocupar(int numero);

#endif
