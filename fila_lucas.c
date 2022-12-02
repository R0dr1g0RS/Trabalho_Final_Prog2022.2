#include "fila_fifo.h"


void f_inicializar(Fila_FIFO **f) {
    *f = NULL;
}

int f_inserir (Fila_FIFO **f, int chave, int valor) {
    Fila_FIFO *novo_no, *aux;
    int num_nos, compara_chave;
    num_nos = f_num_elementos(f); //Numero de nós na fila


    //Verificar se existe alguma chave repetida
    if(num_nos != 0) { //Se a fila estiver vazia não precisa verificar
        while(num_nos != 0) {
            //Compara a chave do novo_nó com as chaves na fila, de trás pra frente;
            compara_chave = f_consultar_chave_por_posicao(f,num_nos);
            if(compara_chave == chave){
                return 0;
            }
            num_nos--;
        }
    }

    //Colocar os dados na struct;
    novo_no = malloc(sizeof(Fila_FIFO));
    if(novo_no == NULL){
        return 0;
    }
    novo_no->conta = chave;
    novo_no->qntd_ope = valor;


    if (*f == NULL) { //Se a fila estiver vazia;
        novo_no->prox = NULL;
        *f = novo_no;
        return 1;
    }

    aux = *f;
    while(aux->prox != NULL)
        aux = aux->prox;
    novo_no->prox = aux->prox;
    aux->prox = novo_no;
    return 1;

}



//Retorna o número de chave do próximo elemento da fila, retirando-o da fila. Retorna -1 se a fila estiver vazia.
int f_obter_proxima_chave (Fila_FIFO **f) {
    Fila_FIFO *no;
    no = *f;
    if(no == NULL)
    {
        return -1;
    }
    *f = no->prox;
    return no->conta;
}

//Retorna a chave do elemento que está na cabeça da fila, sem retirá-lo da fila.
int f_consultar_proxima_chave (Fila_FIFO **f)
{
    Fila_FIFO *no;

    no = *f;
    if(no == NULL)
    {
        return -1;
    }
    return no->conta;
}

//Retorna o valor armazenado no elemento que está na cabeça da fila, sem retirá-lo da fila.
int f_consultar_proximo_valor (Fila_FIFO **f)
{
    Fila_FIFO *no;

    no = *f;
    if(no == NULL)
    {
        return -1;
    }
    return no->qntd_ope;
}

//Retorna o número de elementos presentes na fila.
int f_num_elementos (Fila_FIFO **f){
    Fila_FIFO *aux;
    int count = 0;

    aux = *f;

    if(aux == NULL){
        return count;
    }
    else {
        while(aux != NULL) {
            count++;
            aux = aux->prox;
        }
        return count;
    }
}

//Retorna a chave do posicao-ésimo elemento da fila. Caso não exista a posição desejada,
//retornar -1. A posição se inicia em 1.
int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao){
    Fila_FIFO *aux = *f;
    int chave, posicao_aux;
    posicao_aux = 1; //1
    while(aux != NULL &&posicao_aux != posicao) {
        aux = aux->prox;
        posicao_aux++;
    }
    if (aux == NULL)
        return -1;
    else {
        chave = aux->conta;
        return chave;
    }
}


int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao) {
    
}


void percorrer(Fila_FIFO *f) {
    Fila_FIFO *aux = f;
    while (aux != NULL){
        printf("\n\nConta: %d\nOperaçẽos: %d\n\n", aux->conta, aux->qntd_ope);
        aux = aux->prox;
    }
}
