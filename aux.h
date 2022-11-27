//
// Created by lucas on 24/11/22.
//

typedef struct _arq {
    char *entrada;
    char* saida;
}arq;

typedef struct _atendimento {
    int caixas_qntd;
    int tempo_op;
    int disciplina;
} Atendimento;

typedef struct _cliente {
    int tipo_conta;
    int num_conta;
    int operacoes;
} Cliente;



#ifndef TRABALHO_AUX_H
#define TRABALHO_AUX_H
