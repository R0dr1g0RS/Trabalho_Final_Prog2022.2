#include "escalonador.h"

int main(int narg, char *argv[])
{
    int prox_chave, prox_valor, num_elementos;
    FILE *arq;
    Fila_FIFO *f1, *f2, *f3, *f4, *f5;
    char *nome_ent = (char*)malloc(sizeof(char) * 16), *nome_sai = (char*)malloc(sizeof(char) * 14);
    char nulo[4] = "0", *num_arq = (char*)malloc(sizeof(char) * 4);
    Escalonador *e;
    
    if(strlen(argv[1]) == 4)
    {
        strcat(nome_ent, "entrada-");
        strcat(nome_ent, argv[1]);          
        strcat(nome_ent, ".txt");
        strcat(nome_sai, "saida-");       /*obtendo os nomes dos arquivos*/
        strcat(nome_sai, argv[1]);
        strcat(nome_sai, ".txt");
    }
    else
    {
        while(strlen(nulo) + strlen(argv[1]) < 4)
        {
            strcat(nulo, "0");
        }
        strcat(nulo, argv[1]);
        strcpy(num_arq, nulo);
        strcat(nome_ent, "entrada-");
        strcat(nome_ent, num_arq);
        strcat(nome_ent, ".txt");
        strcat(nome_sai, "saida-");
        strcat(nome_sai, num_arq);
        strcat(nome_sai, ".txt");
    }
    //puts(nome_ent);
    //puts(nome_sai);
    //f_inicializar(&f1);
    //f_inserir(&f1, 755816, 3);
    //percorrer(f1);
    
    e_inicializar(e, 7, 5, 11, 10, 8, 5, 2);
    if(e->premium == NULL)
    {
        printf("Sim");
    }
    else
    {
        printf("Nao");
    }
    
    //e_inserir_por_fila(e, 1, 755816, 3);
    //percorrer(e->premium);
    
    
    return EXIT_SUCCESS;
}
