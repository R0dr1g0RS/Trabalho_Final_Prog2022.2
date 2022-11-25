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
        return 0;
    
    //int novo->NumCon = Ncon;
    //int novo->Numcla = Ncla;
    //int novo->QantOp = Qop;
    //int novo->prox = NULL;
    
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

int f_num_elementos (Fila_FIFO **f)
{
    int i;
    
    
}
