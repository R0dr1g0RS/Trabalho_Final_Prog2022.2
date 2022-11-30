#include "fila_fifo.h"

int main(int narg, char *argv[])
{
    int prox_chave, prox_valor, num_elementos;
    FILE *arq;
    Fila_FIFO *f1, *f2, *f3, *f4, *f5;
    char *nome_ent = (char*)malloc(sizeof(char) * 16), *nome_sai = (char*)malloc(sizeof(char) * 14);
    
    nome_arqvs(nome_ent, nome_sai, argv[1]);
    puts(nome_ent);             /*obtendo os nomes dos arquivos*/
    puts(nome_sai);
    
    f_inicializar(&f1);
    f_inicializar(&f2);
    f_inicializar(&f3);           /*inicializando as filas*/
    f_inicializar(&f4);
    f_inicializar(&f5);
    
    //Ainda tem que ajeitar para funcionar aqui;
    char 
        nulo[4] = "0", 
        sai[20], 
        ent[20],
        *num_arq = (char*)malloc(sizeof(char) * 4);

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
    return EXIT_SUCCESS;
}
