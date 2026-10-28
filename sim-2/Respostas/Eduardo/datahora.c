// #ifndef _DATAHORA_H
// #define _DATAHORA_H


// typedef struct DataHora DataHora;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datahora.h"

struct DataHora {
    int dia, mes, ano, hora, minuto;
};

/**
 * @brief   Cria uma data/hora a partir dos valores informados.
 *
 * @param dia     [entrada]  Dia do mês, inteiro em [1, 31] (válido para o mês/ano).
 * @param mes     [entrada]  Mês, inteiro em [1, 12].
 * @param ano     [entrada]  Ano com 4 dígitos (ex.: 2026), inteiro >= 1.
 * @param hora    [entrada]  Hora do dia, inteiro em [0, 23].
 * @param minuto  [entrada]  Minuto, inteiro em [0, 59].
 *
 * @return  Ponteiro para o DataHora criado (alocado dinamicamente);
 *          NULL se a alocação de memória falhar.
 *
 * @pre     Os valores formam uma data/hora válida (a função NÃO valida).
 * @post    O chamador é dono do DataHora retornado e deve liberá-lo com
 *          liberaDataHora() (ou transferir a posse para outro TAD que o libere).
 */
DataHora *criaDataHora(int dia, int mes, int ano, int hora, int minuto) {
    DataHora *h =  (DataHora *) calloc(1, sizeof(DataHora));
    h->ano = ano;
    h->dia = dia;
    h->hora = hora;
    h->mes = mes;
    h->minuto = minuto;

    return h;
}

/**
 * @brief   Lê uma data/hora da entrada padrão e cria o DataHora correspondente.
 *
 * Lê UMA linha no formato "DD/MM/AAAA HH:MM" (data, um espaço, horário), por
 * exemplo "27/10/2026 08:05", consumindo também a quebra de linha final.
 *
 * @return  Ponteiro para o DataHora lido (mesmas regras de posse de criaDataHora()).
 *
 * @pre     A próxima linha da entrada padrão contém uma data/hora válida no formato
 *          acima.
 */
DataHora *lerDataHora() {
    int dia, mes, ano, hora, minuto;
    scanf("%d/%d/%d %d:%d\n", &dia, &mes, &ano, &hora, &minuto);
    DataHora *h = criaDataHora(dia, mes, ano, hora, minuto);
    return h;
}

long long calcularMinutos(DataHora *data);

/**
 * @brief   Calcula quantos minutos se passaram entre duas datas/horas.
 *
 * O cálculo considera o calendário real:
 *   - meses com 31 dias: 1, 3, 5, 7, 8, 10, 12; com 30 dias: 4, 6, 9, 11;
 *   - fevereiro tem 29 dias em ano bissexto e 28 nos demais;
 *   - um ano é bissexto se for divisível por 400, ou se for divisível por 4 e NÃO
 *     for divisível por 100 (ex.: 2028 e 2000 são bissextos; 2026 e 2100 não são);
 *   - cada dia tem 24 * 60 = 1440 minutos.
 * Exemplos:
 *   inicio = 27/10/2026 08:50, fim = 27/10/2026 10:05  ->  75
 *   inicio = 27/10/2026 23:30, fim = 28/10/2026 00:10  ->  40
 *   inicio = 28/02/2028 12:00, fim = 01/03/2028 12:00  ->  2880 (2028 é bissexto)
 *
 * @param inicio  [entrada]  Data/hora inicial (não-nula).
 * @param fim     [entrada]  Data/hora final (não-nula).
 *
 * @return  Diferença em minutos (fim - inicio). É >= 0 sempre que fim não for
 *          anterior a inicio.
 *
 * @pre     inicio != NULL e fim != NULL.
 * @note    Nenhuma das duas datas/horas é modificada ou liberada.
 */
int diferencaMinutosDataHora(DataHora *inicio, DataHora *fim) {
    long long minInicio = calcularMinutos(inicio);
    long long minFim = calcularMinutos(fim);

    return (int)(minFim - minInicio);
}

/**
 * @brief   Imprime a data/hora na saída padrão no formato "DD/MM/AAAA HH:MM".
 *
 * Dia, mês, hora e minuto são impressos SEMPRE com dois dígitos e o ano com quatro
 * (zeros à esquerda quando necessário). Ex.: "05/03/2027 08:05". Há exatamente um
 * espaço entre a data e o horário. NÃO imprime quebra de linha nem espaços
 * antes/depois.
 *
 * @param dh  [entrada]  Data/hora a imprimir (não-nula).
 * @pre     dh != NULL.
 */
void imprimeDataHora(DataHora *dh) {
    printf("%02d/%02d/%04d %02d:%02d", dh->dia, dh->mes, dh->ano, dh->hora, dh->minuto);
}

/**
 * @brief   Libera a memória alocada para uma data/hora.
 *
 * @param dh  [entrada]  Data/hora a liberar.
 * @post    A memória apontada por dh é liberada; o ponteiro não deve mais ser usado.
 */
void liberaDataHora(DataHora *dh) {
    free(dh);
}

//retorna 1 se for bissexto e 0 caso contrario
int ehBissexto(int ano) {
    if(!(ano%400))
        return 1;
    else if(!(ano%4)) {
        if(ano%100)
            return 1;
        else
            return 0;
    }

    return 0;

}

//retorna dias mes
int diasMes(int mes, int ano) {
    //1, 3, 5, 7, 8, 10, 12
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    //4, 6, 9, 11
    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        if(ehBissexto(ano)) 
            return 29;
        else
            return 28;
    }
}

long long calcularMinutos(DataHora *data) {
    long long total = 0;

    // Minutos dos anos anteriores
    for (int i = 1; i < data->ano; i++) {
        if (ehBissexto(i))
            total += 366 * 1440;
        else
            total += 365 * 1440;
    }

    // Minutos dos meses anteriores
    for (int i = 1; i < data->mes; i++) {
        total += diasMes(i, data->ano) * 1440;
    }

    // Minutos dos dias anteriores
    total += (data->dia - 1) * 1440;

    // Minutos das horas
    total += data->hora * 60;

    // Minutos restantes
    total += data->minuto;

    return total;
}
