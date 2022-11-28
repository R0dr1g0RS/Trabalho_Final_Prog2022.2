#include "fila_fifo.h"

void nome_arqvs(char *ent, char *sai, char *argv)
{
    char nulo[4] = "0", *num_arq = (char*)malloc(sizeof(char) * 4);
    
    if(strlen(argv) == 4)
    {
        strcat(ent, "entrada-");
        strcat(ent, argv);
        strcat(ent, ".txt");
        strcat(sai, "saida-");
        strcat(sai, argv);
        strcat(sai, ".txt");
    }
    else
    {
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
}

int ler_arq(char *arq_nome)
{
    FILE *arq;
    int caixa, tempo;
    int e_1, e_2, e_3, e_4, e_5; //disciplina de atendimento para cada classe de conta;
    int num_conta, num_operacoes;
    char classe_conta[8];
    
    arq = fopen(arq_nome, "rt");

    if (arq == NULL){
        printf("Nao foi possivel ler o arquivo\n");
        return 0;
    }

    fscanf(arq, "qtde de caixas = %d\n", &caixa);
    printf("Quantidade de Caixas: %d\n", caixa);
    fscanf(arq, "delta t = %d\n", &tempo);
    printf("DeltaT: %d\n", tempo);
    fscanf(arq,"disciplina de escalonamento = {%d,%d,%d,%d,%d}\n", &e_1, &e_2,&e_3, &e_4, &e_5);
    printf("E1: %d\n", e_1);
    printf("E2: %d\n", e_2);
    printf("E3: %d\n", e_3);
    printf("E4: %d\n", e_4);
    printf("E5: %d\n", e_5);

    while(fscanf(arq,"%s - conta %d - %d operacao(oes)", classe_conta, &num_conta , &num_operacoes) != EOF){
        printf("Classe: %s\n", classe_conta);
        printf("Conta: %d\n", num_conta);
        printf("Operações: %d\n", num_operacoes);
    }
    return 1;
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
