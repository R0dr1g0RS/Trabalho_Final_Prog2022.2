#include <stdlib.h>
#include <stdio.h>
#include "escalonador.h"
#include "logtree.h"

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
    f_inicializar(&e->leezu);
    f_inicializar(&e->bronze);
    f_inicializar(&e->prata);
    f_inicializar(&e->ouro);
    f_inicializar(&e->premium);
    
    e->caixas = caixas;
    e->delta_t = delta_t;
    
    e->n_1 = n_1;
    e->n_2 = n_2;
    e->n_3 = n_3;
    e->n_4 = n_4;
    e->n_5 = n_5;

    e->count_n_1 = n_1; 
    e->count_n_2 = n_2;
    e->count_n_3 = n_3;
    e->count_n_4 = n_4;
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
        f_inserir(&e->premium, num_conta, qtde_operacoes);
    }
    if (classe == 2) // Cliente ouro
    {
        f_inserir(&e->ouro, num_conta, qtde_operacoes);
    }
    if (classe == 3) // Cliente prata
    {
        f_inserir(&e->prata, num_conta, qtde_operacoes);
    }
    if (classe == 4) // Cliente bronze
    {
        f_inserir(&e->bronze, num_conta, qtde_operacoes);
    }
    if (classe == 5) // Cliente leezu
    {
        f_inserir(&e->leezu, num_conta, qtde_operacoes);
    }    
    return (1);
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
            if (e->count_n_5 == 0)
            {
                e->count_n_1 = e->n_1;
                e->count_n_2 = e->n_2;
                e->count_n_3 = e->n_3;
                e->count_n_4 = e->n_4;
                e->count_n_5 = e->n_5;
            }
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
    FILE *entrada;
    int 
        caixas, 
        tempo, 
        N_1, N_2, N_3, N_4, N_5;
    char 
        classe[10];
    int 
        conta, 
        operacao;
    int i;

    entrada = fopen(nome_arq_conf, "r");
    if (entrada == NULL) 
    {
        return 0;
    }

    fscanf(entrada, "qtde de caixas = %d\n", &caixas);
    fscanf(entrada, "delta t = %d\n", &tempo);
    fscanf(entrada, "disciplina de escalonamento = {%d,%d,%d,%d,%d}\n", &N_1, &N_2, &N_3, &N_4, &N_5);

    e_inicializar(e, caixas, tempo, N_1, N_2, N_3, N_4, N_5);

    i = 0;

    while ((fscanf(entrada, "%s - conta %d - %d operacao(oes)", classe, &conta, &operacao) != EOF)) 
    {
        if (strcmp(classe, "Premium") == 0) 
        {
            e_inserir_por_fila(e, 1, conta, operacao);
        } 
        else if (strcmp(classe, "Ouro") == 0) 
        {
            e_inserir_por_fila(e, 2, conta, operacao);
        } 
        else if (strcmp(classe, "Prata") == 0) 
        {
            e_inserir_por_fila(e, 3, conta, operacao);
        } 
        else if (strcmp(classe, "Bronze") == 0) 
        {
            e_inserir_por_fila(e, 4, conta, operacao);
        } 
        else if (strcmp(classe, "Leezu") == 0)
        {
            e_inserir_por_fila(e, 5, conta, operacao);
        }
    }
    return(1);
};


/*
Executar a simulação do atendimento, lendo o arquivo de configuração de nome “nome_arq_in” e escrevendo 
o resultado do processamento para arquivo de nome “nome_arq_out”. 
*/
void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out)
{
    e_conf_por_arquivo(e, nome_arq_in);

    Log
        *clientes;
    log_inicializar(&clientes);

    int
        tmp_total = 0,  // Conta o tempo de espera dos clientes

        num_clients_cx[e->caixas], // Quantidade de clientes atendidos em cada caixa

        oper,       // Recebe a quantidade de operações de cada cliente
        classe,     // Recebe a classe de cada cliente
        NumCont,    // Recebe o número de conta de cada cliente
        Qtd_cx_ocp = 0, // Contador de caixas ocupados
                            //  | O tempo que o caixa com o menor quantidades de operações levará para terminar.
        tmp_reduzir = 0,    //  |           Esse tempo será subtraído do cronômetro de todo caixa
                            //  |               Afim de liberar pelo menos um caixa
        cron_cx[e->caixas-1]; // Cronômetro de cada caixa, com o tempo que resta p/ terminar de operar

    for (int i = 0; i < e->caixas; i++)
    {
        cron_cx[i] = 0;
    }

    float 
        t_medio_[5],    // Tempo médio de espera de cada classe

        total_cl_[5],   // Quantidade de clientes por classe

        oper_ttl_[5],   // Quantidade de operações totais por classe

        o_medio_[5];    // Quantidade média de operações de cada classe

    for (int i = 0; i < 5; i++)
    {
        oper_ttl_[i] = 0;
        total_cl_[i] = 0;
        o_medio_[i] = 0;
        t_medio_[i] = 0;
    }

    char
        class[5][8];
    class[0][0] = 'P'; class[0][1] = 'r'; class[0][2] = 'e'; class[0][3] = 'm'; class[0][4] = 'i'; class[0][5] = 'u'; class[0][6] = 'm'; class[0][7] = '\0';   
    class[1][0] = 'O'; class[1][1] = 'u'; class[1][2] = 'r'; class[1][3] = 'o'; class[1][4] = '\0';
    class[2][0] = 'P'; class[2][1] = 'r'; class[2][2] = 'a'; class[2][3] = 't'; class[2][4] = 'a'; class[2][5] = '\0';
    class[3][0] = 'B'; class[3][1] = 'r'; class[3][2] = 'o'; class[3][3] = 'n'; class[3][4] = 'z'; class[3][5] = 'e'; class[3][6] = '\0';
    class[4][0] = 'L'; class[4][1] = 'e'; class[4][2] = 'e'; class[4][3] = 'z'; class[4][4] = 'u'; class[4][5] = '\0';

    FILE *saida;

    saida = fopen(nome_arq_out, "wt");

    while (e_consultar_prox_fila(e) != -1)
    {
        if (Qtd_cx_ocp == e->caixas)
        {
            Qtd_cx_ocp = 0;
            tmp_reduzir = cron_cx[0];
            for (int i = 0; i < e->caixas; i++)
            {
                if (tmp_reduzir > cron_cx[i])
                {
                    tmp_reduzir = cron_cx[i];
                }
            }
            for (int k = 0; k < e->caixas; k++)
            {
                cron_cx[k] -= tmp_reduzir;
                if (cron_cx[k] != 0)
                {
                    Qtd_cx_ocp++;
                }
            }
            
        }
        
        tmp_total += tmp_reduzir;
        for (int i = 0; i < e->caixas; i++)
        {
            if (cron_cx[i] == 0 && e_consultar_prox_fila(e) != -1)
            {
                classe = e_consultar_prox_fila(e);
                oper = e_consultar_prox_qtde_oper(e);
                cron_cx[i] = e_consultar_tempo_prox_cliente(e);
                NumCont = e_obter_prox_num_conta(e);
                Qtd_cx_ocp++;
                log_registrar(&clientes, NumCont, classe, tmp_total, i+1);
                for (int k = 0; k < 6; k++)
                {
                    if (classe-1 == k)
                    {
                        oper_ttl_[k] += oper;
                        fprintf(saida, "T = %d min: Caixa %d chama da categoria %s cliente da conta %d para realizar %d operacao(oes).\n", tmp_total, i+1, class[k], NumCont, oper);
                    }
                }
            }
        }            
    }

    tmp_reduzir = cron_cx[0];
    for (int i = 0; i <= e->caixas-1; i++)
    {
        if (tmp_reduzir < cron_cx[i])
        {
            tmp_reduzir = cron_cx[i];   //  Tempo que falta para encerrarem todos os atendimentos
        }
    }
    tmp_total += tmp_reduzir;

    fprintf(saida, "Tempo total de atendimento: %d minutos.\n", tmp_total);


    for (int i = 0; i < 5; i++)
    {
        t_medio_[i] = log_media_por_classe(&clientes, i+1);
        total_cl_[i] = log_obter_contagem_por_classe(&clientes, i+1);
        fprintf(saida, "Tempo medio de espera dos %.0f clientes %s: %.2f\n", total_cl_[i], class[i], t_medio_[i]);    

        o_medio_[i] = (oper_ttl_[i]/total_cl_[i]);    
    }
    

    for (int i = 0; i < 5; i++)
    {
        fprintf(saida, "Quantidade media de operacoes por cliente %s = %.2f\n", class[i], o_medio_[i]);    
    }

    for (int i = 0; i < e->caixas; i++)
    {
        num_clients_cx[i] = log_obter_contagem_por_caixa(&clientes, i+1);
        fprintf(saida, "O caixa de número %d atendeu %d clientes.\n", (i+1), num_clients_cx[i]);
    }
    fclose(saida);
}
