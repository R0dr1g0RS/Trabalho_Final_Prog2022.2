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
        novo_no->caixa_num = caixa;
        novo_no->timer = timer;

        novo_no->esquerda= NULL;
        novo_no->direita = NULL;
        *l = novo_no; //A raiz da arvore é igual novo nó
    }
    //Se a arvore não estiver vazia
    else{
        if (conta < (*l)->conta_num && (*l)->esquerda != NULL) //Se a classe do novo_nó for menor que a de *l e ele possuir filho esquerdo;
            log_registrar(&(*l)->esquerda, conta, classe, timer, caixa); //Chamar a função novamente no lado esquerdo de *l;

        else if (conta > (*l)->conta_num && (*l)->direita != NULL) //Se a classe do novo_nó for maior que a de *l e ele possuir filho direito;
            log_registrar(&(*l)->direita, conta, classe, timer, caixa); //Chamar a função novamente no lado direito de *l;


        else {
            novo_no = malloc(sizeof(Log));
            novo_no->conta_num = conta;
            novo_no->conta_classe = classe;
            novo_no->caixa_num = caixa;
            novo_no->timer = timer;

            novo_no->esquerda= NULL;
            novo_no->direita = NULL;

            if(conta < (*l)->conta_num)  //Se a classe do novo_nó for menor que a de *l e ela não possuir filho esquerdo;
                (*l)->esquerda = novo_no;
            else                             //Se a classe do novo_nó for maior que a de *l e ela não possuir filho direito;
                (*l)->direita = novo_no;

        }
    }

}

float log_media_por_classe(Log **l, int classe) {
    float tempo_medio, tempo_total, qntd_contas;
    tempo_total = log_obter_soma_por_classe(&(*l), classe);
    qntd_contas = log_obter_contagem_por_classe(&(*l), classe);
    tempo_medio = tempo_total/qntd_contas;
    //Soma do tempo de espera de uma classe dividido pela quantidade de contas dessa classe;

    return tempo_medio;
}
int log_obter_soma_por_classe(Log **l, int classe){
    int esq, dir;

    if (*l == NULL){
        return 0;
    }
    esq = log_obter_soma_por_classe(&(*l)->esquerda,classe);
    dir = log_obter_soma_por_classe(&(*l)->direita,classe);
    if (classe != (*l)->conta_classe)
        return 0 + esq + dir;
    else
        return (*l)->timer + esq + dir;
}

int log_obter_contagem_por_classe(Log **l, int classe){
    int esq, dir;

    if (*l == NULL){
        return 0;
    }
    esq = log_obter_contagem_por_classe(&(*l)->esquerda,classe);
    dir = log_obter_contagem_por_classe(&(*l)->direita,classe);

    if (classe != (*l)->conta_classe)
        return 0 + esq + dir;
    else
        return 1 + esq +dir;
}

int log_obter_contagem_por_caixa(Log **l, int caixa)
{
    int esq, dir;

    if (*l == NULL){
        return 0;
    }
    esq = log_obter_contagem_por_caixa(&(*l)->esquerda, caixa);
    dir = log_obter_contagem_por_caixa(&(*l)->direita, caixa);

    if (caixa != (*l)->caixa_num)
        return 0 + esq + dir;
    else
        return 1 + esq +dir;
};
