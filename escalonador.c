#include <stdlib.h>
#include <stdio.h>
#include "escalonador.h"


// Desenvolver  um  escalonador  de  filas  que  trata  de  forma  diferenciada  5  filas,  com  as  características  de 
// disciplina  citadas  no  enunciado  do  trabalho.  
// Os  arquivos  no  projeto  para  o  escalonador  deverão  ser: 
// “escalonador.c” e “escalonador.h”. 


/*
Inicializa o escalonador, alocando e inicializando as 5 filas, que serão atendidas por “caixas” caixas, onde cada 
operação é tratada em “delta_t” minutos por um caixa, e o escalonamento utiliza a Disciplina de Atendimento 
representada por {n_1; n_2; n_2; n_4; n_5}, nos termos do que foi definido na página 1 deste enunciado. 
*/
void e_inicializar(Escalonador *e, int caixas, int delta_t, int n_1, int n_2, int n_3, int n_4, int n_5)
{
    // Alocação
    e = (Escalonador *)malloc(sizeof(Escalonador));
    if (e == NULL)
        exit(EXIT_FAILURE);

    // Ninguém nas filas
    e->premium = NULL;
    e->ouro = NULL;
    e->prata = NULL;
    e->bronze = NULL;
    e->leezu = NULL;

    e->delta_t = delta_t;
    e->caixas = caixas;
    e->n_1 = n_1;
    e->count_n_1 = n_1; 
    e->n_2 = n_2;
    e->count_n_2 = n_2;
    e->n_3 = n_3;
    e->count_n_3 = n_3;
    e->n_4 = n_4;
    e->count_n_4 = n_4;
    e->n_5 = n_5;
    e->count_n_5 = n_5;    
};


/*
Insere  na  fila  “classe”  o  cliente  de  número  “num_conta”,  que  pretende  realizar  “qtde_operacoes”  operações 
bancárias. 
*/
int e_inserir_por_fila(Escalonador *e, int classe, int num_conta, int qtde_operacoes)
{
    if (classe == 1) // Cliente premium
    {
        if (e->premium == NULL) // Caso onde a fila está vazia
        {
            e->premium =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Alocação na memória
            if (e->premium == NULL)
                return(0);
            
            e->premium->NumCla = classe;
            e->premium->NumCon = num_conta;
            e->premium->QntOp = qtde_operacoes; // Cliente inserido!
            e->premium->prox = NULL; 
            return(1);
        }

        Fila_FIFO
            *p =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Ponteiro auxiliar para percorrer a fila
        if (p == NULL)
            return(0);
        p = e->premium;

        while (p->prox != NULL) 
        {
            p = p->prox;
        }
        
        p->prox = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
        if (p->prox == NULL)
            return(0);

        p = p->prox;
        p->NumCla = classe;
        p->NumCon = num_conta;
        p->QntOp = qtde_operacoes;
        p->prox = NULL;
        return(1);
    }
    if (classe == 2) // Cliente ouro
    {
        if (e->ouro == NULL) // Caso onde a fila está vazia
        {
            e->ouro =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Alocação na memória
            if (e->ouro == NULL)
                return(0);
            
            e->ouro->NumCla = classe;
            e->ouro->NumCon = num_conta;
            e->ouro->QntOp = qtde_operacoes; // Cliente inserido!
            e->ouro->prox = NULL; 
            return(1);
        }

        Fila_FIFO
            *p =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Ponteiro auxiliar para percorrer a fila
        if (p == NULL)
            return(0);
        p = e->ouro;

        while (p->prox != NULL) 
        {
            p = p->prox;
        }
        
        p->prox = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
        if (p->prox == NULL)
            return(0);

        p = p->prox;
        p->NumCla = classe;
        p->NumCon = num_conta;
        p->QntOp = qtde_operacoes;
        p->prox = NULL;
        return(1);        
    }
    if (classe == 3) // Cliente prata
    {
        if (e->prata == NULL) // Caso onde a fila está vazia
        {
            e->prata =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Alocação na memória
            if (e->prata == NULL)
                return(0);
            
            e->prata->NumCla = classe;
            e->prata->NumCon = num_conta;
            e->prata->QntOp = qtde_operacoes; // Cliente inserido!
            e->prata->prox = NULL; 
            return(1);
        }

        Fila_FIFO
            *p =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Ponteiro auxiliar para percorrer a fila
        if (p == NULL)
            return(0);
        p = e->prata;

        while (p->prox != NULL) 
        {
            p = p->prox;
        }
        
        p->prox = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
        if (p->prox == NULL)
            return(0);

        p = p->prox;
        p->NumCla = classe;
        p->NumCon = num_conta;
        p->QntOp = qtde_operacoes;
        p->prox = NULL;
        return(1);        
    }
    if (classe == 4) // Cliente bronze
    {
        if (e->bronze == NULL) // Caso onde a fila está vazia
        {
            e->bronze =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Alocação na memória
            if (e->bronze == NULL)
                return(0);
            
            e->bronze->NumCla = classe;
            e->bronze->NumCon = num_conta;
            e->bronze->QntOp = qtde_operacoes; // Cliente inserido!
            e->bronze->prox = NULL; 
            return(1);
        }

        Fila_FIFO
            *p =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Ponteiro auxiliar para percorrer a fila
        if (p == NULL)
            return(0);
        p = e->bronze;

        while (p->prox != NULL) 
        {
            p = p->prox;
        }
        
        p->prox = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
        if (p->prox == NULL)
            return(0);

        p = p->prox;
        p->NumCla = classe;
        p->NumCon = num_conta;
        p->QntOp = qtde_operacoes;
        p->prox = NULL;
        return(1);        
    }
    if (classe == 5) // Cliente leezu
    {
        if (e->leezu == NULL) // Caso onde a fila está vazia
        {
            e->leezu =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Alocação na memória
            if (e->leezu == NULL)
                return(0);
            
            e->leezu->NumCla = classe;
            e->leezu->NumCon = num_conta;
            e->leezu->QntOp = qtde_operacoes; // Cliente inserido!
            e->leezu->prox = NULL; 
            return(1);
        }

        Fila_FIFO
            *p =  (Fila_FIFO *)malloc(sizeof(Fila_FIFO)); // Ponteiro auxiliar para percorrer a fila
        if (p == NULL)
            return(0);
        p = e->leezu;

        while (p->prox != NULL) 
        {
            p = p->prox;
        }
        
        p->prox = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
        if (p->prox == NULL)
            return(0);

        p = p->prox;
        p->NumCla = classe;
        p->NumCon = num_conta;
        p->QntOp = qtde_operacoes;
        p->prox = NULL;
        return(1);
    }    
};


/*
Retorna  o  número  da  conta  do  próximo  cliente  a  ser  atendido  de  acordo  com  a  Disciplina  de  Atendimento, 
retirando-o da sua respectiva fila. 
*/
int e_obter_prox_num_conta(Escalonador *e)
{
    if (e->count_n_1 != 0) // Existem clientes na fila premium que não foram atendidos nesta rodada
    {
        if (e->premium == NULL) // Fila vazia
        {
            e->count_n_1 = 0;
        }
        else
        {
            int
                num_conta = e->premium->NumCon; // Guardando o número da conta para ser retornado posteriormente
            
            e->premium = e->premium->prox;
            e->count_n_1--; // Conta-se menos um desta rodada
            return(num_conta);
        }
    } 
    // Não existem clientes premium desta rodada
    if (e->count_n_2 != 0) // Existem clientes na fila ouro que não foram atendidos nesta rodada
    {
        if (e->ouro == NULL) // Fila vazia
        {
            e->count_n_2 = 0;
        }
        else
        {
            int
                num_conta = e->ouro->NumCon; // Guardando o número da conta para ser retornado posteriormente
            
            e->ouro = e->ouro->prox;
            e->count_n_2--; // Conta-se menos um desta rodada
            return(num_conta);
        }
    }
    // Não existem clientes ouro desta rodada
    if (e->count_n_3 != 0) // Existem clientes na fila prata que não foram atendidos nesta rodada
    {
        if (e->prata == NULL) // Fila vazia
        {
            e->count_n_3 = 0;
        }
        else
        {
            int
                num_conta = e->prata->NumCon; // Guardando o número da conta para ser retornado posteriormente
            
            e->prata = e->prata->prox;
            e->count_n_3--; // Conta-se menos um desta rodada
            return(num_conta);
        }
    }
    // Não existem clientes prata desta rodada
    if (e->count_n_4 != 0) // Existem clientes na fila bronze que não foram atendidos nesta rodada
    {
        if (e->bronze == NULL) // Fila vazia
        {
            e->count_n_4 = 0;
        }
        else
        {
            int
                num_conta = e->bronze->NumCon; // Guardando o número da conta para ser retornado posteriormente
            
            e->bronze = e->bronze->prox;
            e->count_n_4--; // Conta-se menos um desta rodada
            return(num_conta);
        }
    }
    // Não existem clientes bronze desta rodada
    if (e->count_n_5 != 0) // Existem pelo menos um cliente leezu para ser atendido
    {
        if (e->leezu == NULL) // Fila vazia
        {
            e->count_n_5 = 0;
        }
        else
        {
            int
                num_conta = e->leezu->NumCon; // Guardando o número da conta para ser retornado posteriormente
            
            e->leezu = e->leezu->prox;
            e->count_n_5--; // Conta-se menos um desta rodada
            return(num_conta);
        }
    }
    // Não há mais clientes para serem atendidos
    return(-1);
};


/*
Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento, sem 
retirá-lo da sua respectiva fila. 
*/
int e_consultar_prox_num_conta(Escalonador *e)
{
    if (e->count_n_1 != 0)
    {
        if (e->premium == NULL)
            e->count_n_1 = 0;
        else
        {
            return(e->premium->NumCon);
        }
    }
    if (e->count_n_2 != 0)
    {
        if (e->ouro == NULL)
            e->count_n_2 = 0;
        else
        {
            return(e->ouro->NumCon);
        }
    }
    if (e->count_n_3 != 0)
    {
        if (e->prata == NULL)
            e->count_n_3 = 0;
        else
        {
            return(e->prata->NumCon);
        }
    }
    if (e->count_n_4 != 0)
    {
        if (e->bronze == NULL)
            e->count_n_4 = 0;
        else
        {
            return(e->bronze->NumCon);
        }
    }
    if (e->count_n_5 != 0)
    {
        if (e->leezu == NULL)
            e->count_n_5 = 0;
        else
        {
            return(e->leezu->NumCon);
        }
    }
    return(-1); // Sem clientes
};


/*
Retorna  a  quantidade  de  operações  bancárias  que  o  próximo  cliente  das  filas  pretende  realizar  com  o  caixa, 
sem retirá-lo da sua respectiva fila. 
*/
int e_consultar_prox_qtde_oper (Escalonador *e)
{
    if (e->count_n_1 != 0)
    {
        if (e->premium == NULL)
            e->count_n_1 = 0;
        else
        {
            return(e->premium->QntOp);
        }
    }
    if (e->count_n_2 != 0)
    {
        if (e->ouro == NULL)
            e->count_n_2 = 0;
        else
        {
            return(e->ouro->QntOp);
        }
    }
    if (e->count_n_3 != 0)
    {
        if (e->prata == NULL)
            e->count_n_3 = 0;
        else
        {
            return(e->prata->QntOp);
        }
    }
    if (e->count_n_4 != 0)
    {
        if (e->bronze == NULL)
            e->count_n_4 = 0;
        else
        {
            return(e->bronze->QntOp);
        }
    }
    if (e->count_n_5 != 0)
    {
        if (e->leezu == NULL)
            e->count_n_5 = 0;
        else
        {
            return(e->leezu->QntOp);
        }
    }
    return(-1); // Sem clientes
};


/*
Retorna a próxima fila que será atendida de acordo com a Disciplina de Atendimento.
*/
int e_consultar_prox_fila (Escalonador *e)
{
    if (e->count_n_1 != 0)
    {
        if (e->premium == NULL)
            e->count_n_1 = 0;
        else
        {
            return(1);
        }
    }
    if (e->count_n_2 != 0)
    {
        if (e->ouro == NULL)
            e->count_n_2 = 0;
        else
        {
            return(2);
        }
    }
    if (e->count_n_3 != 0)
    {
        if (e->prata == NULL)
            e->count_n_3 = 0;
        else
        {
            return(3);
        }
    }
    if (e->count_n_4 != 0)
    {
        if (e->bronze == NULL)
            e->count_n_4 = 0;
        else
        {
            return(4);
        }
    }
    if (e->count_n_5 != 0)
    {
        if (e->leezu == NULL)
            e->count_n_5 = 0;
        else
        {
            return(5);
        }
    }
    return(-1); // Sem clientes
}


/*
Retorna a quantidade total (soma) de clientes esperando atendimento em todas as filas.
*/
int e_consultar_qtde_clientes (Escalonador *e)
{
    int 
        cont = 0;
    Fila_FIFO
        *contador;
    contador = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
    if (e->premium != NULL)
    {
        contador = e->premium;
        cont++;
        while (contador->prox != NULL)
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->ouro != NULL)
    {
        contador = e->ouro;
        cont++;
        while (contador->prox != NULL)
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->prata != NULL)
    {
        contador = e->prata;
        cont++;
        while (contador->prox != NULL)
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->bronze != NULL)
    {
        contador = e->bronze;
        cont++;
        while (contador->prox != NULL)
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->leezu != NULL)
    {
        contador = e->leezu;
        cont++;
        while (contador->prox != NULL)
        {
            cont++;
            contador = contador->prox;
        }
    }
    free(contador);
    return(cont);
};


/*
Retorna o tempo necessário para que o próximo cliente a ser atendido realize todas as operações financeiras 
que deseja, sem retirá-lo da sua respectiva fila. Retornar -1 caso não tenha nenhum cliente em todas as filas. 
*/
int e_consultar_tempo_prox_cliente (Escalonador *e)
{
    if (e->count_n_1 != 0)
    {
        if (e->premium == NULL)
            e->count_n_1 = 0;
        else
        {
            return(e->premium->QntOp * e->delta_t);
        }
    }
    if (e->count_n_2 != 0)
    {
        if (e->ouro == NULL)
            e->count_n_2 = 0;
        else
        {
            return(e->ouro->QntOp * e->delta_t);
        }
    }
    if (e->count_n_3 != 0)
    {
        if (e->prata == NULL)
            e->count_n_3 = 0;
        else
        {
            return(e->prata->QntOp * e->delta_t);
        }
    }
    if (e->count_n_4 != 0)
    {
        if (e->bronze == NULL)
            e->count_n_4 = 0;
        else
        {
            return(e->bronze->QntOp * e->delta_t);
        }
    }
    if (e->count_n_5 != 0)
    {
        if (e->leezu == NULL)
            e->count_n_5 = 0;
        else
        {
            return(e->leezu->QntOp * e->delta_t);
        }
    }
    return(-1); // Sem clientes
};


/*
Realiza a configuração de inicialização do escalonador através da leitura do arquivo de configuração de nome 
“nome_arq_conf”, retornando 1 em caso de sucesso e 0 caso contrário. 
*/
int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf)
{
    
};


/*
Executar a simulação do atendimento, lendo o arquivo de configuração de nome “nome_arq_in” e escrevendo 
o resultado do processamento para arquivo de nome “nome_arq_out”. 
*/
void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out)
{
    FILE *entradas;
    int caixa, tempo;
    int e_1, e_2, e_3, e_4, e_5; //disciplina de atendimento para cada classe de conta;
    int num_conta, num_operacoes;
    char classe_conta[8];

    entradas = fopen(nome_arq_in, "r");

    if (entradas == NULL){
        printf("Nao foi possivel ler o arquivo\n");
    }
    else
    {
        fscanf(entradas, "qtde de caixas = %d\n", &caixa);
        printf("%d\n", caixa);
        fscanf(entradas, "delta t = %d\n", &tempo);
        printf("%d\n", tempo);
        fscanf(entradas,"disciplina de escalonamento = {%d,%d,%d,%d,%d}\n", &e_1, &e_2,&e_3, &e_4, &e_5);
        printf("%d\n", e_1);
        printf("%d\n", e_2);
        printf("%d\n", e_3);
        printf("%d\n", e_4);
        printf("%d\n", e_5);
        //Essa parte é só pra ver se tava pegando os arquivos corretamente;
        //Tem que fazer ir alocando na fila de acordo com a disciplina de escalonamento;
        while(fscanf(entradas,"%s - conta %d - %d operacao(oes)", classe_conta, &num_conta , &num_operacoes) != EOF){
            printf("Classe:\t%s\n", classe_conta);
            printf("Conta:\t%d\n", num_conta);
            printf("Operações:\t%d\n", num_operacoes);
        }
    }
};
