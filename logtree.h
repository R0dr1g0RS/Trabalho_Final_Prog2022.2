#ifndef TRABALHO_LOGTREE_H
#define TRABALHO_LOGTREE_H

typedef struct _arvore {
    int conta_num, conta_classe, timer, caixa_qntd;
    struct _arvore *direita, *esquerda;

} Log;


void log_inicializar(Log **);

void log_registrar(Log **, int, int, int, int);

float log_media_por_classe(Log **, int);

int log_obter_soma_por_classe(Log **, int);

int log_obter_contagem_por_classe(Log **, int);




#endif //TRABALHO_LOGTREE_H
