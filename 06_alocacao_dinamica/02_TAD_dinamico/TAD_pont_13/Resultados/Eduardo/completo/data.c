#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// typedef struct {
//     int dia;
//     int mes;
//     int ano;
// } Data;

/*
Função que cria uma data a partir do dia, mês e ano fornecidos e retorna um ponteiro para a data criada
@param dia: Dia da data.
@param mes: Mês da data.
@param ano: Ano da data.
@return Data criada.
*/
Data *criaData(int dia, int mes, int ano) {
    Data *d = calloc(1, sizeof(Data));
    d->ano = ano;
    d->dia = dia;
    d->mes = mes;
    return d;
}

/*
Função que lê uma data do formato DD/MM/AAAA a partir da entrada padrão e retorna um ponteiro para a data lida.
@return Data lida.
*/
Data *lerData() {
    int dia, mes, ano;
    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    return criaData(dia, mes, ano);;
}

/*
Função que calcula a diferença em anos entre duas datas. A diferença é calculada como o número de anos completos entre a data inicial e a data atual.
Ex: Se a data inicial for 15/08/2000 e a data atual for 14/08/2023, a diferença será 22 anos. 
@param inicial: Data inicial.
@param atual: Data atual.
@return Diferença em anos entre as duas datas.
*/
int diferencaAnoData(Data *inicial, Data *atual) {
    int diff = atual->ano - inicial->ano;
    if(atual->mes > inicial->mes)
        return diff;
    else if(atual->dia >= inicial->dia && atual->mes == inicial->mes)
        return diff;
    else
        return diff - 1;
}

/*
Função que imprime uma data no formato DD/MM/AAAA.
@param d: Data a ser impressa.
*/
void imprimeData(Data *d) {
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}

/*
Função que libera a memória alocada para uma data.
@param d: Ponteiro para a data a ser liberada.
*/
void liberaData(Data *d) {
    free(d);
}