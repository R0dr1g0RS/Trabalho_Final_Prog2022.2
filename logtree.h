#ifndef logtree_h
#define logtree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _arvore 
{
    int 
        conta_num,  // Número da conta do cliente.
        conta_classe,  // Número da classe do cliente.
        timer,   // Tempo de espera do cliente.
        caixa_num;  // Número do caixa no qual o cliente foi atendido.
    struct _arvore 
        *direita,  // Filho direito do elemento na árvore
        *esquerda; // Filho esquerdo do elemento na árvore
}Log;

void log_inicializar(Log **);

void log_registrar(Log **, int, int, int, int);

float log_media_por_classe(Log **, int);

int log_obter_soma_por_classe(Log **, int);

int log_obter_contagem_por_classe(Log **, int);

int log_obter_contagem_por_caixa(Log **l, int caixa);

#endif
