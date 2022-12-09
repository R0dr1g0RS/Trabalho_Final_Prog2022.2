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
    f_inicializar(&e->leezu);
    f_inicializar(&e->bronze);
    f_inicializar(&e->prata);  // Inicializando as filas de cada classe.
    f_inicializar(&e->ouro);
    f_inicializar(&e->premium);
    
    e->caixas = caixas;   // Salvando o número de caixas no escalonador.
    e->delta_t = delta_t; // Salvando o delta t no escalonador.
    
    e->n_1 = n_1;
    e->n_2 = n_2;
    e->n_3 = n_3;   // Salvando a disciplina de atendimento no escalonador.
    e->n_4 = n_4;
    e->n_5 = n_5;

    e->count_n_1 = n_1; 
    e->count_n_2 = n_2;
    e->count_n_3 = n_3;  // Salvando os contadores de cada fila no escalonador.
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
    // Não existem clientes Premium desta rodada.
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
    // Não existem clientes Ouro desta rodada.
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
    // Não existem clientes Prata desta rodada.
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
    // Não existem clientes Bronze desta rodada.
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
    // Não há mais clientes para serem atendidos.
    return(-1);
};


/*
Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento, sem 
retirá-lo da sua respectiva fila. 
*/
int e_consultar_prox_num_conta(Escalonador *e)
{
    if (e->count_n_1 != 0)  // Existem clientes na fila premium que não foram atendidos nesta rodada.
    {                       
        if (e->premium == NULL)  // Fila vazia
            e->count_n_1 = 0;
        else
        {
            return(e->premium->NumCon);
        }
    }
    // Não existem clientes Premium desta rodada.
    if (e->count_n_2 != 0)  // Existem clientes na fila Ouro que não foram atendidos nesta rodada.
    {                       
        if (e->ouro == NULL)  // Fila vazia
            e->count_n_2 = 0;
        else
        {
            return(e->ouro->NumCon);
        }
    }
    // Não existem clientes Ouro desta rodada.
    if (e->count_n_3 != 0)  // Existem clientes na fila Prata que não foram atendidos nesta rodada.
    {                       
        if (e->prata == NULL)  // Fila vazia
            e->count_n_3 = 0;
        else
        {
            return(e->prata->NumCon);
        }
    }
    // Não existem clientes Prata desta rodada.
    if (e->count_n_4 != 0)  // Existem clientes na fila Bronze que não foram atendidos nesta rodada.
    {                       
        if (e->bronze == NULL)  // Fila vazia
            e->count_n_4 = 0;
        else
        {
            return(e->bronze->NumCon);
        }
    }
    // Não existem clientes Bronze desta rodada.
    if (e->count_n_5 != 0)  // Existem clientes na fila Leezu que não foram atendidos nesta rodada.
    {                       
        if (e->leezu == NULL)  // Fila vazia
            e->count_n_5 = 0;
        else
        {
            return(e->leezu->NumCon);
        }
    }
    // Não há mais clientes para serem atendidos.
    return(-1); 
};


/*
Retorna  a  quantidade  de  operações  bancárias  que  o  próximo  cliente  das  filas  pretende  realizar  com  o  caixa, 
sem retirá-lo da sua respectiva fila. 
*/
int e_consultar_prox_qtde_oper (Escalonador *e)
{
    if (e->count_n_1 != 0)  // Existem clientes na fila Premium que não foram atendidos nesta rodada.
    {                   
        if (e->premium == NULL)  // Fila vazia
            e->count_n_1 = 0;
        else
        {
            return(e->premium->QntOp);
        }
    }
    // Não existem clientes Premium desta rodada.
    if (e->count_n_2 != 0)  // Existem clientes na fila Ouro que não foram atendidos nesta rodada.
    {                       
        if (e->ouro == NULL)  // Fila vazia
            e->count_n_2 = 0;
        else
        {
            return(e->ouro->QntOp);
        }
    }
    // Não existem clientes Ouro desta rodada.
    if (e->count_n_3 != 0)  // Existem clientes na fila Prata que não foram atendidos nesta rodada.
    {                       
        if (e->prata == NULL)  // Fila vazia
            e->count_n_3 = 0;
        else
        {
            return(e->prata->QntOp);
        }
    }
    // Não existem clientes Prata desta rodada.
    if (e->count_n_4 != 0)  // Existem clientes na fila Bronze que não foram atendidos nesta rodada.
    {                       
        if (e->bronze == NULL)  // Fila vazia
            e->count_n_4 = 0;
        else
        {
            return(e->bronze->QntOp);
        }
    }
    // Não existem clientes Bronze desta rodada.
    if (e->count_n_5 != 0)  // Existem clientes na fila Leezu que não foram atendidos nesta rodada.
    {                       
        if (e->leezu == NULL)  // Fila vazia
            e->count_n_5 = 0;
        else
        {
            return(e->leezu->QntOp);
        }
    }
    // Não há mais clientes para serem atendidos.
    return(-1); 
};


/*
Retorna a próxima fila que será atendida de acordo com a Disciplina de Atendimento.
*/
int e_consultar_prox_fila (Escalonador *e)
{
    if (e->count_n_1 != 0)  // Existem clientes na fila Premium que não foram atendidos nesta rodada.
    {                       
        if (e->premium == NULL)  // Fila vazia
            e->count_n_1 = 0;
        else
        {
            return(1);  
        }
    }
    // Não existem clientes Premium desta rodada.
    if (e->count_n_2 != 0)  // Existem clientes na fila Ouro que não foram atendidos nesta rodada.
    {                       
        if (e->ouro == NULL)  // Fila vazia
            e->count_n_2 = 0;
        else
        {
            return(2);
        }
    }
    // Não existem clientes Ouro desta rodada.
    if (e->count_n_3 != 0)  // Existem clientes na fila Prata que não foram atendidos nesta rodada.
    {                       
        if (e->prata == NULL)  // Fila vazia
            e->count_n_3 = 0;
        else
        {
            return(3);
        }
    }
    // Não existem clientes Prata desta rodada.
    if (e->count_n_4 != 0)  // Existem clientes na fila Bronze que não foram atendidos nesta rodada.
    {                       
        if (e->bronze == NULL)  // Fila vazia
            e->count_n_4 = 0;
        else
        {
            return(4);
        }
    }
    // Não existem clientes Bronze desta rodada.
    if (e->count_n_5 != 0)  // Existem clientes na fila Leezu que não foram atendidos nesta rodada.
    {                       
        if (e->leezu == NULL)  // Fila vazia
            e->count_n_5 = 0;
        else
        {
            return(5);
        }
    }
    // Não há mais clientes para serem atendidos.
    return(-1); 
}


/*
Retorna a quantidade total (soma) de clientes esperando atendimento em todas as filas.
*/
int e_consultar_qtde_clientes (Escalonador *e)
{
    int cont = 0;
    Fila_FIFO *contador;
    
    if (e->premium != NULL) // Se a fila Premium não estiver vazia.
    {
        contador = e->premium;
        cont++;
        while (contador->prox != NULL) // Percorre a fila Premium e soma +1 ao contador para cada cliente na fila.
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->ouro != NULL) // Se a fila Ouro não estiver vazia.
    {
        contador = e->ouro;
        cont++;
        while (contador->prox != NULL) // Percorre a fila Ouro e soma +1 ao contador para cada cliente na fila.
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->prata != NULL) // Se a fila Prata não estiver vazia.
    {
        contador = e->prata;
        cont++;
        while (contador->prox != NULL) // Percorre a fila Prata e soma +1 ao contador para cada cliente na fila.
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->bronze != NULL) // Se a fila Bronze não estiver vazia.
    {
        contador = e->bronze;
        cont++;
        while (contador->prox != NULL) // Percorre a fila Bronze e soma +1 ao contador para cada cliente na fila.
        {
            cont++;
            contador = contador->prox;
        }
    }
    if (e->leezu != NULL) // Se a fila Leezu não estiver vazia.
    {
        contador = e->leezu;
        cont++;
        while (contador->prox != NULL) // Percorre a fila Leezu e soma +1 ao contador para cada cliente na fila.
        {
            cont++;
            contador = contador->prox;
        }
    }
    return(cont);
};


/*
Retorna o tempo necessário para que o próximo cliente a ser atendido realize todas as operações financeiras 
que deseja, sem retirá-lo da sua respectiva fila. Retornar -1 caso não tenha nenhum cliente em todas as filas. 
*/
int e_consultar_tempo_prox_cliente (Escalonador *e)
{
    if (e->count_n_1 != 0)  // Existem clientes na fila Premium que não foram atendidos nesta rodada.
    {                       
        if (e->premium == NULL)  // Fila vazia
            e->count_n_1 = 0;
        else
        {
            return(e->premium->QntOp * e->delta_t);
        }
    }
    // Não existem clientes Premium desta rodada.
    if (e->count_n_2 != 0)  // Existem clientes na fila Ouro que não foram atendidos nesta rodada.
    {                       
        if (e->ouro == NULL)  // Fila vazia
            e->count_n_2 = 0;
        else
        {
            return(e->ouro->QntOp * e->delta_t);
        }
    }
    // Não existem clientes Ouro desta rodada.
    if (e->count_n_3 != 0)  // Existem clientes na fila Prata que não foram atendidos nesta rodada.
    {                       
        if (e->prata == NULL)  // Fila vazia
            e->count_n_3 = 0;
        else
        {
            return(e->prata->QntOp * e->delta_t);
        }
    }
    // Não existem clientes Prata desta rodada.
    if (e->count_n_4 != 0)  // Existem clientes na fila Bronze que não foram atendidos nesta rodada.
    {                       
        if (e->bronze == NULL)  // Fila vazia
            e->count_n_4 = 0;
        else
        {
            return(e->bronze->QntOp * e->delta_t);
        }
    }
    // Não existem clientes Bronze desta rodada.
    if (e->count_n_5 != 0)  // Existem clientes na fila Leezu que não foram atendidos nesta rodada.
    {                       
        if (e->leezu == NULL)  // Fila vazia
            e->count_n_5 = 0;
        else
        {
            return(e->leezu->QntOp * e->delta_t);
        }
    }
    // Não há mais clientes para serem atendidos.
    return(-1); 
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
        N_1, N_2, N_3, N_4, N_5,
        conta, 
        operacao;
    char 
        classe[10];

    entrada = fopen(nome_arq_conf, "r");
    if (entrada == NULL) // Se o arquivo não for corretamente lido, retorna 0.
    {
        return 0;
    }

    fscanf(entrada, "qtde de caixas = %d\n", &caixas);  // Lê a quantidade de caixas disponíveis.
    fscanf(entrada, "delta t = %d\n", &tempo);    // Lê o delta t.
    fscanf(entrada, "disciplina de escalonamento = {%d,%d,%d,%d,%d}\n", &N_1, &N_2, &N_3, &N_4, &N_5);  // Lê a disciplina de atendimento.

    e_inicializar(e, caixas, tempo, N_1, N_2, N_3, N_4, N_5);

    while ((fscanf(entrada, "%s - conta %d - %d operacao(oes)", classe, &conta, &operacao) != EOF)) // Lê a classe, o número
    {                                                                                               // da conta e a classe do cliente e
        if (strcmp(classe, "Premium") == 0) // Insere na fila Premium.
        {
            e_inserir_por_fila(e, 1, conta, operacao);
        } 
        else if (strcmp(classe, "Ouro") == 0) // Insere na fila Ouro.
        {
            e_inserir_por_fila(e, 2, conta, operacao);
        } 
        else if (strcmp(classe, "Prata") == 0) // Insere na fila Prata.
        {
            e_inserir_por_fila(e, 3, conta, operacao);
        } 
        else if (strcmp(classe, "Bronze") == 0) // Insere na fila Bronze.
        {
            e_inserir_por_fila(e, 4, conta, operacao);
        } 
        else if (strcmp(classe, "Leezu") == 0) // Insere na fila Leezu.
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
    Log *clientes;
    float 
        t_medio_[5],    // Tempo médio de espera de cada classe.
        total_cl_[5],   // Quantidade de clientes por classe.
        oper_ttl_[5],   // Quantidade de operações totais por classe.
        o_medio_[5];    // Quantidade média de operações de cada classe.
    char
        class[5][8];
    class[0][0] = 'P'; class[0][1] = 'r'; class[0][2] = 'e'; class[0][3] = 'm'; class[0][4] = 'i'; class[0][5] = 'u'; class[0][6] = 'm'; class[0][7] = '\0';   
    class[1][0] = 'O'; class[1][1] = 'u'; class[1][2] = 'r'; class[1][3] = 'o'; class[1][4] = '\0';
    class[2][0] = 'P'; class[2][1] = 'r'; class[2][2] = 'a'; class[2][3] = 't'; class[2][4] = 'a'; class[2][5] = '\0';
    class[3][0] = 'B'; class[3][1] = 'r'; class[3][2] = 'o'; class[3][3] = 'n'; class[3][4] = 'z'; class[3][5] = 'e'; class[3][6] = '\0';
    class[4][0] = 'L'; class[4][1] = 'e'; class[4][2] = 'e'; class[4][3] = 'z'; class[4][4] = 'u'; class[4][5] = '\0';
    FILE *saida;
    
    e_conf_por_arquivo(e, nome_arq_in);
    
    log_inicializar(&clientes);

    int
        i, k,   // Índices.
        tmp_total = 0,  // Conta o tempo de espera dos clientes.
        num_clients_cx[e->caixas], // Quantidade de clientes atendidos em cada caixa.
        oper,       // Recebe a quantidade de operações de cada cliente.
        classe,     // Recebe a classe de cada cliente.
        NumCont,    // Recebe o número de conta de cada cliente.
        Qtd_cx_ocp = 0, // Contador de caixas ocupados.
                            //  | O tempo que o caixa com o menor quantidades de operações levará para terminar.
        tmp_reduzir = 0,    //  |           Esse tempo será subtraído do cronômetro de todo caixa
                            //  |               Afim de liberar pelo menos um caixa.
        cron_cx[e->caixas-1]; // Cronômetro de cada caixa, com o tempo que resta para terminar de operar.

    for (i = 0; i < e->caixas; i++)
    {
        cron_cx[i] = 0;  // Zerando o cronômetro de cada caixa.
    }

    for (i = 0; i < 5; i++)
    {
        oper_ttl_[i] = 0;  // Zerando a quantidade total de operações por classe.
        total_cl_[i] = 0;  // Zerando o total de cliente por classe.
        o_medio_[i] = 0;   // Zerando a quantidade média de operacões cada classe.
        t_medio_[i] = 0;   // Zerando o tempo médio de espera de cada classe
    }

    saida = fopen(nome_arq_out, "wt");  // Abrindo o arquivo de saída para escrita.

    while (e_consultar_prox_fila(e) != -1) // Enquanto todas as filas não estiverem vazias.
    {
        if (Qtd_cx_ocp == e->caixas)  // Se a quantidade de caixas ocupados é igual a quantidade de caixas.
        {
            Qtd_cx_ocp = 0;  // Zera os caixas ocupados.
            // Procura o caixa que falta menos tempo para acabar de realizar todas as suas operações
            // e salva o menor tempo para reduzir.
            tmp_reduzir = cron_cx[0];  
            for (i = 0; i < e->caixas; i++)
            {
                if (tmp_reduzir > cron_cx[i])
                {
                    tmp_reduzir = cron_cx[i];
                }
            }
            // Reduz o tempo de todos os caixas e conta quantos caixas ainda estão ocupados.
            for (k = 0; k < e->caixas; k++)
            {
                cron_cx[k] -= tmp_reduzir;
                if (cron_cx[k] != 0)
                {
                    Qtd_cx_ocp++;
                }
            }
        }
        tmp_total += tmp_reduzir;  //  Soma ao tempo total o tempo que passou.
        for (i = 0; i < e->caixas; i++)  
        {
            if (cron_cx[i] == 0 && e_consultar_prox_fila(e) != -1)
            {
                classe = e_consultar_prox_fila(e); // Recebendo a classe do próximo da fila.
                oper = e_consultar_prox_qtde_oper(e); // Recebendo a quantidade de operações do próximo da fila.
                cron_cx[i] = e_consultar_tempo_prox_cliente(e); // Recebendo o tempo que o próximo da fila irá demorar.
                NumCont = e_obter_prox_num_conta(e); // Recebendo o número da conta do próximo e o retira da fila.
                Qtd_cx_ocp++;  // Aumenta a quantidade de caixas ocupados.
                log_registrar(&clientes, NumCont, classe, tmp_total, i+1); // Insere os dados do cliente na árvore binária.
                for (k = 0; k < 6; k++) // 
                {
                    if (classe-1 == k)
                    {
                        oper_ttl_[k] += oper;  // Somando a quantidade de operações do cliente na quantidade de operações totais da fila.
                        fprintf(saida, "T = %d min: Caixa %d chama da categoria %s cliente da conta %d para realizar %d operacao(oes).\n", tmp_total, i+1, class[k], NumCont, oper);
                        // Registra o tempo da chamada, o caixa que chamou, a categoria,
                        // o número da conta e o número de operações do cliente atual no documento.
                    }
                }
            }
        }            
    }

    tmp_reduzir = cron_cx[0]; 
    for (i = 0; i <= e->caixas-1; i++)
    {
        if (tmp_reduzir < cron_cx[i])
        {
            tmp_reduzir = cron_cx[i];   //  Tempo que falta para encerrarem todos os atendimentos
        }
    }
    tmp_total += tmp_reduzir;

    fprintf(saida, "Tempo total de atendimento: %d minutos.\n", tmp_total);
    // Registra o tempo total no documento.

    for (i = 0; i < 5; i++)
    {
        t_medio_[i] = log_media_por_classe(&clientes, i+1);  // Registra o tempo médio da da classe.
        total_cl_[i] = log_obter_contagem_por_classe(&clientes, i+1);  // Registra a quantidade de cliente de cada classe.
            fprintf(saida, "Tempo medio de espera dos %.0f clientes %s: %.2f\n", total_cl_[i], class[i], t_medio_[i]);
            // Registra o número de clientes e o tempo médio de espera dos cliente de cada classe no documento.
        o_medio_[i] = (oper_ttl_[i]/total_cl_[i]); // Registra a quantidade média de operações de cada classe. 
    }
    
    for (i = 0; i < 5; i++)
    {
        fprintf(saida, "Quantidade media de operacoes por cliente %s = %.2f\n", class[i], o_medio_[i]);
        // Registra a quantidade média de operações por classe no documento.
    }

    for (i = 0; i < e->caixas; i++)
    {
        num_clients_cx[i] = log_obter_contagem_por_caixa(&clientes, i+1); // Registra o número de clientes de cada caixa.
        fprintf(saida, "O caixa de número %d atendeu %d clientes.\n", (i+1), num_clients_cx[i]);
        // Registra o número de clientes que cada caixa atendeu no documento.
    }
    fclose(saida); // Fecha o documento de escrita.
}
