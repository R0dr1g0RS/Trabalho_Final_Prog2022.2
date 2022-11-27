// tá pegando todos os dados;
//os prints são apenas para visualizar, depois apagar;
//tem que ver como as informações serão passadas para a lista;
int ler_arq(Atendimento ** l, char *arq_nome){
    FILE *entradas;
    int caixa, tempo;
    int e_1, e_2, e_3, e_4, e_5; //disciplina de atendimento para cada classe de conta;
    int num_conta, num_operacoes;
    char classe_conta[8];

    entradas = fopen(arq_nome, "r");

    if (entradas == NULL){
        printf("entrou\n");
        return 0;
    }

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

    while(fscanf(entradas,"%s - conta %d - %d operacao(oes)", classe_conta, &num_conta , &num_operacoes) != EOF){
        printf("Classe:\t%s\n", classe_conta);
        printf("Conta:\t%d\n", num_conta);
        printf("Operações:\t%d\n", num_operacoes);
    }
    return 1;
}
