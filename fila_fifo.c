#include "fila_fifo.h"

void nome_arqvs(char *ent, char *sai, char *argv)
{
    char nulo[4] = "0", *num_arq = (char*)malloc(sizeof(char) * 4);
    
    while(strlen(nulo) + strlen(argv) < 4)
    {
        strcat(nulo, "0");
    }
    strcat(nulo, argv);
    strcpy(num_arq, nulo);
    strcat(ent, "entrada-");
    strcat(ent, num_arq);
    strcat(ent, ".txt");
    strcat(sai, "saida-");
    strcat(sai, num_arq);
    strcat(sai, ".txt");
}

void f_inicializar (Fila_FIFO **f)
{
    *f = NULL;
}

int f_inserir (Fila_FIFO **f, int chave, int valor)
{
    Fila_FIFO *novo, *no;
    
    novo = (Fila_FIFO*)malloc(sizeof(Fila_FIFO));
    if(novo == NULL)
    {
        return 0;
    }
    
    novo->NumCon = chave;
    novo->QntOp = valor;
    novo->prox = NULL;
    
    if(*f == NULL)
    {
        *f = novo;
        return 1;
    }
    no = *f;
    while(no->prox != NULL)
    {
        no = no->prox;
    }
    novo->prox = no->prox;
    no->prox = novo;
    return 1;
}

int f_obter_proxima_chave (Fila_FIFO **f)
{
    Fila_FIFO *no;
    
    no = *f;
    if(no == NULL)
    {
        return -1;
    }
    *f = no->prox;
    return no->NumCon;
}

int f_consultar_proxima_chave (Fila_FIFO **f)
{
    Fila_FIFO *no;
    
    no = *f;
    if(no == NULL)
    {
        return -1;
    }
    return no->NumCon;
}

int f_consultar_proximo_valor (Fila_FIFO **f)
{
    Fila_FIFO *no;
    
    no = *f;
    if(no == NULL)
    {
        return -1;
    }
    return no->QntOp;
}

int f_num_elementos (Fila_FIFO **f)
{
    int i = 0;
    Fila_FIFO *inicio = *f;
    
    while(inicio != NULL)
    {
        i++;
        inicio = inicio->prox;
    }
    return i;
}

int f_consultar_chave_por_posicao (Fila_FIFO **f, int posicao)
{
    int i = 1;
    Fila_FIFO *inicio = *f;

    while(inicio != NULL && i < posicao)
    {
        i++;
        inicio = inicio->prox;
    }
    return inicio->NumCon;
    
    return -1;
}

int f_consultar_valor_por_posicao (Fila_FIFO **f, int posicao)
{
    int i = 1;
    Fila_FIFO *inicio = *f;

    while(inicio != NULL && i < posicao)
    {
        i++;
        inicio = inicio->prox;
    }
    return inicio->QntOp;
    
    return -1;
}

void percorrer(Fila_FIFO *f)
{
    Fila_FIFO *inicio = f;
    
    while(inicio != NULL)
    {
        printf("Numero da Conta:%d\nQuantida de Operaçoes:%d\n\n", inicio->NumCon, inicio->QntOp);
        inicio = inicio->prox;
    }
}
