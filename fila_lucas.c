#include "fila_fifo.h"


// Inicializa a fila.
void f_inicializar(Fila_FIFO **f) 
{
    *f = NULL; //Inicializa a fila.
}


// Insere um determinado valor inteiro indexado por um valor de chave na fila. Retorna 1 se a inserção for bem
// sucedida e 0 se houver algum problema (duplicação de chave ou falta de memória).
int f_inserir (Fila_FIFO **f, int chave, int valor) 
{
    Fila_FIFO *novo_no, *no;
    int num_nos, compara_chave;
    
    num_nos = f_num_elementos(f); //Numero de nós na fila;

    // 1. Verificar se existe alguma chave repetida:
    if(num_nos != 0) // Se a fila estiver vazia, não precisa verificar;
    { 
        while(num_nos != 0) 
        {
            //Compara a chave de novo_no com as chaves na fila, de trás pra frente;
            compara_chave = f_consultar_chave_por_posicao(f,num_nos);
            if(compara_chave == chave)
                return 0; // Se a chave for repetida, retorna 0;
            num_nos--;
        }
    }

    // 2. Colocar os dados na struct:
    novo_no = malloc(sizeof(Fila_FIFO));
    if(novo_no == NULL)
        return 0; // Se houver falta de memória, retorna 0;
    novo_no->NumCon = chave;
    novo_no->QntOp = valor;

    if (*f == NULL) 
    { //Se a fila estiver vazia;
        novo_no->prox = NULL;
        *f = novo_no;
        return 1;
    }
    no = *f;
    while(no->prox != NULL) // Se a fila não estiver vazia, percorre ela 
        no = no->prox;     // e coloca o novo elemento no final da fila.
    novo_no->prox = no->prox;
    no->prox = novo_no;
    return 1;
}


//Retorna o número de chave do próximo elemento da fila, retirando-o da fila. Retorna -1 se a fila estiver vazia.
int f_obter_proxima_chave (Fila_FIFO **f) 
{
    Fila_FIFO *no = *f;
    
    if(no == NULL) // Se a fila estiver vazia, retorna -1;
        return -1; 
    *f = no->prox; // O primeiro nó da fila é retirado e o próximo nó passa a ser o primeiro;
    return no->NumCon; // Retorna a proxima chave da fila.
}


//Retorna a chave do elemento que está na cabeça da fila, sem retirá-lo da fila.
int f_consultar_proxima_chave (Fila_FIFO **f)
{
    Fila_FIFO *no = *f;

    if(no == NULL) // Se a fila estiver vazia, retorna -1;
        return -1;
    return no->NumCon; // Retorna a proxima chave da fila.
}


//Retorna o valor armazenado no elemento que está na cabeça da fila, sem retirá-lo da fila.
int f_consultar_proximo_valor (Fila_FIFO **f)
{
    Fila_FIFO *no = *f;

    if(no == NULL) // Se a fila estiver vazia, retorna -1;
        return -1;
    return no->QntOp; // Retorna a proxima valor da fila.
}


//Retorna o número de elementos presentes na fila.
int f_num_elementos (Fila_FIFO **f)
{
    Fila_FIFO *no = *f;
    int count = 0;

    while(no != NULL) 
    {
        count++; // Adiciona +1 ao contador para cada nó não-nulo;
        no = no->prox;
    }
    return count; // retorna o numéro de elementos.
}


//Retorna a chave do posicao-ésimo elemento da fila. Caso não exista a posição desejada,
//retornar -1. A posição se inicia em 1.
int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao)
{
    Fila_FIFO *no = *f;
    int posicao_aux, chave;
    
    posicao_aux = 1; // A posição se inicia em 1;
    while(no != NULL && posicao_aux != posicao) // Enquanto o nó for não-nulo e a posicao_aux
    {                                           // for diferente de posicao ele percorre a fila;
        no = no->prox;
        posicao_aux++;
    }
    if (no == NULL) // Se o nó for nulo, a posição desejada não existe na fila;
        return -1;
    chave = no->NumCon;
    return chave; // Retorna a chave do nó na posição desejada da fila.
}


//Retorna o valor do posicao-ésimo elemento da fila. Caso não exista a posição desejada,
//retornar -1. A posição se inicia em 1.
int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao) 
{
    Fila_FIFO *no = *f;
    int posicao_aux, valor;
    
    posicao_aux = 1; // A posição se inicia em 1;
    while(no != NULL && posicao_aux != posicao) // Enquanto o nó for não-nulo e a posicao_aux
    {                                           // for diferente de posicao ele percorre a fila;
        no = no->prox;
        posicao_aux++;
    }
    if (no == NULL) // Se o nó for nulo, a posição desejada não existe na fila;
        return -1;
    valor = no->QntOp;
    return valor; // Retorna o valor do nó na posição desejada da fila.
}


void percorrer(Fila_FIFO *f) { // Essa função vai ser removida é so pra testar
    Fila_FIFO *aux = f;
    while (aux != NULL){
        printf("\nConta: %d\nOperacoes: %d\n", aux->NumCon, aux->QntOp);
        aux = aux->prox;
    }
}
