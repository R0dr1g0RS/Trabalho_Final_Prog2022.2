#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"


int main(int argc, char * argv[]) {
    struct escalonador e;
    char *nome_ent = (char*)malloc(sizeof(char) * 16), *nome_sai = (char*)malloc(sizeof(char) * 14);
    char nulo[4] = "0", *num_arq = (char*)malloc(sizeof(char) * 4);

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
    
    e_rodar(&e, nome_ent, nome_sai);    /*Rodar o programa*/

    return EXIT_SUCCESS;
}
