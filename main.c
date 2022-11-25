#include "fila_fifo.h"

int main(int narg, char *argv[])
{
    int i;
    FILE *arq;
    Fila_FIFO *f1, *f2, *f3, *f4, *f5;
    char *nome_ent = (char*)malloc(sizeof(char) * 16), *nome_sai = (char*)malloc(sizeof(char) * 14);
    
    nome_arqvs(nome_ent, nome_sai, argv[1]);
    puts(nome_ent);
    puts(nome_sai);
    
    f_inicializar(&f1);
    f_inicializar(&f2);
    f_inicializar(&f3);
    f_inicializar(&f4);
    f_inicializar(&f5);
    

    return EXIT_SUCCESS;
}
