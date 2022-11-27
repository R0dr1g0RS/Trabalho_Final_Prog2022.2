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
    
    f_inserir(&f1, 755816, 3);                            //
    f_inserir(&f1, 814107, 8);                            //
    f_inserir(&f1, 746865, 3);                            //
    //prox_chave = f_obter_proxima_chave(&f1);            //
    //prox_valor = f_consultar_proximo_valor(&f1);        //
    num_elementos = f_num_elementos(&f1);                 //
    prox_chave = f_consultar_chave_por_posicao(&f1, 3);   /*aqui eu so tava testando as funçoes se quiserem apagar podem*/
    prox_valor = f_consultar_valor_por_posicao(&f1, 3);   //
    //printf("%d\n", prox_chave);                         //
    printf("%d\n", prox_valor);                           //
    //printf("%d\n", num_elementos);                      //
    percorrer(f1);                                        //
    
    
    

    return EXIT_SUCCESS;
}
