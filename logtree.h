#ifndef TRABALHO_LOGTREE_H
#define TRABALHO_LOGTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _arvore {
    int conta_num, conta_classe, timer, caixa_num;
    struct _arvore *direita, *esquerda;
}Log;


void log_inicializar(Log **);

void log_registrar(Log **, int, int, int, int);

float log_media_por_classe(Log **, int);

int log_obter_soma_por_classe(Log **, int);

int log_obter_contagem_por_classe(Log **, int);

