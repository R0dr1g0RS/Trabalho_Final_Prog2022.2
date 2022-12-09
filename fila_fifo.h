#ifndef fila_fifo_h
#define fila_fifo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fifo
{
    int NumCon;
    int NumCla;      
    int QntOp;
    struct Fifo *prox;
} Fila_FIFO;

void f_inicializar (Fila_FIFO **f);

int f_inserir (Fila_FIFO **f, int chave, int valor);

int f_obter_proxima_chave (Fila_FIFO **f);

int f_consultar_proxima_chave (Fila_FIFO **f);

int f_consultar_proximo_valor (Fila_FIFO **f);

int f_num_elementos (Fila_FIFO **f);

int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao);

int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao);

#endif
