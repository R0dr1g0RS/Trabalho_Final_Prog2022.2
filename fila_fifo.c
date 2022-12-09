#include "fila_fifo.h"

/*
Inicializa a fila.
*/
void f_inicializar (Fila_FIFO **f)
{
    *f = NULL;
}


/*
Insere um determinado valor inteiro indexado por um valor de chave na fila. Retorna 1 se a inserção for bem
sucedida e 0 se houver algum problema (duplicação de chave ou falta de memória).
*/
int f_inserir (Fila_FIFO **f, int chave, int valor)
{
    Fila_FIFO *novo, *no;
    
    novo = (Fila_FIFO*)malloc(sizeof(Fila_FIFO));  // Alocação de memória.
    if(novo == NULL)       
    {
        return 0;
    }
    
    novo->NumCon = chave;
    novo->QntOp = valor;   // Inserindo a chave e o valor.
    novo->prox = NULL;
    
    if(*f == NULL)  // Se a fila estiver vazia
    {
        *f = novo;  // Coloca o novo nó no início da fila.
        return 1;
    }
    no = *f;     // Ponteiro auxiliar para percorrer a fila.
    while(no->prox != NULL)
    {
        if(no->NumCon == chave) // Testa se a chave nova é repetida. Se sim, retorna erro.
        {
            free(novo); // libera o espaço alocado.
            return 0;  
        }
        no = no->prox;
    }
    novo->prox = no->prox;  // Coloca o novo nó no final da fila.
    no->prox = novo;        
    return 1;
}


/*
Retorna o número de chave do próximo elemento da fila, retirando-o da fila. 
Retorna -1 se a fila estiver vazia.
*/
int f_obter_proxima_chave (Fila_FIFO **f)
{
    Fila_FIFO *no = *f;
    
    if(no == NULL)
    {
        return -1;
    }
    *f = no->prox;   // O proximo nó passa a ser o primeiro da fila.
    return no->NumCon;
}


/*
Retorna a chave do elemento que está na cabeça da fila, sem retirá-lo da fila.
*/
int f_consultar_proxima_chave (Fila_FIFO **f)
{
    Fila_FIFO *no = *f;
    
    if(no == NULL)
    {
        return -1;
    }
    return no->NumCon;
}


/*
Retorna o valor armazenado no elemento que está na cabeça da fila, sem retirá-lo da fila.
*/
int f_consultar_proximo_valor (Fila_FIFO **f)
{
    Fila_FIFO *no = *f;
    
    if(no == NULL)
    {
        return -1;
    }
    return no->QntOp;
}


/*
Retorna o número de elementos presentes na fila.
*/
int f_num_elementos (Fila_FIFO **f)
{
    int i = 0;
    Fila_FIFO *no = *f;
    
    while(no != NULL)   // Percorre a fila e soma i + 1 para cada elemento da fila.
    {
        i++;
        no = no->prox;
    }
    return i;
}


/*
Retorna a chave do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1.
A posição se inicia em 1.
*/
int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao)
{
    int i = 1;
    Fila_FIFO *no = *f;
    
    while(no != NULL && i < posicao)  // Percorre a fila até chegar na posição desejada.
    {
        i++;
        no = no->prox;
    }
    if(no == NULL)   // Se a posição não estiver presente na fila, retorna -1.
    {                
        return -1;
    }
    return no->NumCon;
}


/*
Retorna o valor do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1.
A posição se inicia em 1.
*/
int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao)
{
    int i = 1;
    Fila_FIFO *no = *f;
    
    while(no != NULL && i < posicao) // Percorre a fila até chegar na posição desejada.
    {
        i++;
        no = no->prox;
    }
    if(no == NULL)  // Se a posição não estiver presente na fila, retorna -1.
    {
        return -1;
    }
    return no->QntOp;
}
