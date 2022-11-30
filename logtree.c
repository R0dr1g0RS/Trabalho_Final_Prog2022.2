
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logtree.h"

//Inicializa a árvore com o primeiro nó sendo NULL;
void log_inicializar(Log **l){
    *l = NULL;
}

//Adicionar novos nós na arvore;
void log_registrar(Log **l, int conta, int classe, int timer, int caixa){
    Log *novo_no;

//Se a arvore estiver vazia o novo nó sera alocado na raiz dela;
    if(*l == NULL) {
        novo_no = malloc(sizeof(Log)); //alocar memoria para o novo nó;

        novo_no->conta_num = conta;
        novo_no->conta_classe = classe;
        novo_no->caixa_qntd = caixa;
        novo_no->timer = timer;

        novo_no->esquerda= NULL;
        novo_no->direita = NULL;
        *l = novo_no; //A raiz da arvore é igual novo nó
    }
    //Se a arvore não estiver vazia
    else{
        if (classe < (*l)->conta_classe && (*l)->esquerda != NULL) //Se a classe do novo_nó for menor que a de *l e ele possuir filho esquerdo;
            log_registrar(&(*l)->esquerda, conta, classe, timer, caixa); //Chamar a função novamente no lado esquerdo de *l;

        else if (classe > (*l)->conta_classe && (*l)->direita != NULL) //Se a classe do novo_nó for maior que a de *l e ele possuir filho direito;
            log_registrar(&(*l)->direita, conta, classe, timer, caixa); //Chamar a função novamente no lado direito de *l;


        else {
            novo_no = malloc(sizeof(Log));
            novo_no->conta_num = conta;
            novo_no->conta_classe = classe;
            novo_no->caixa_qntd = caixa;
            novo_no->timer = timer;

            novo_no->esquerda= NULL;
            novo_no->direita = NULL;

            if(classe < (*l)->conta_classe)  //Se a classe do novo_nó for menor que a de *l e ela não possuir filho esquerdo;
                (*l)->esquerda = novo_no;
            else                             //Se a classe do novo_nó for maior que a de *l e ela não possuir filho direito;
                (*l)->direita = novo_no;
        }
    }
    
}

float log_media_por_classe(Log **l, int classe) {
    float tempo_medio;
    tempo_medio = log_obter_soma_por_classe(&(*l), classe)/ log_obter_contagem_por_classe(&(*l), classe);
    //Soma do tempo de espera de uma classe dividido pela quantidade de contas dessa classe;

    return tempo_medio;
}

int log_obter_soma_por_classe(Log **l, int classe){
    Log *raiz = (*l);
    if(raiz == NULL){
        return 0;
        //Se a raiz for nula então a árvore está vazia e não há elementos para contar;
    }
    else {
        if(raiz->conta_classe == classe) //Se a classe do nó for igual a classe especificada
            return raiz->timer + log_obter_soma_por_classe(&raiz->esquerda, classe) + log_obter_soma_por_classe (&raiz->direita, classe);
            //Soma o timer do nó atual com os retornos da chamada recursiva pelos lados esquerdo e direito da arvore;
        else
            return 0 + log_obter_soma_por_classe(&raiz->esquerda, classe) + log_obter_soma_por_classe (&raiz->direita, classe);
            //Soma os retornos da chamada recursiva pelo lado esquerdo e direito da arvore;
    }
}

int log_obter_contagem_por_classe(Log **l, int classe){
    Log *raiz = (*l);
    if(raiz == NULL){
        return 0;
        //Se a raiz for nula então a árvore está vazia e não há elementos para contar;
    }
    else {
        if (raiz->conta_classe == classe) //Se a classe do nó for igual a classe especificada
            return 1 + log_obter_contagem_por_classe(&raiz->esquerda, classe) + log_obter_contagem_por_classe(&raiz->direita, classe);
            //Soma 1 com os retornos da chamada recursiva pelos lados esquerdo e direito da arvore;
        else
            return 0 + log_obter_contagem_por_classe(&raiz->esquerda, classe) + log_obter_contagem_por_classe(&raiz->direita, classe);
            //Faz uma chamada recursiva, descendo pelos 2 lados da arvore, somando os retornos;
    }
}
