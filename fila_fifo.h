#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fifo
{
    int NumCon;
    int NumCla; 
    int QantOp;
    struct Fifo *prox;
} Fila_FIFO;

void nome_arqvs(char *ent, char *sai, char *argv);

void f_inicializar (Fila_FIFO **f);

int f_inserir (Fila_FIFO **f, int chave, int valor);

int f_num_elementos (Fila_FIFO **f);
