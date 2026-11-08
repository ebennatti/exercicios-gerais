
// #ifndef _VEICULO_H
// #define _VEICULO_H

// /*
//  * TAD Veiculo
//  * -----------
//  * Representa um veículo elétrico cadastrado no sistema utilizando as 
//  * informações descritas no enunciado da atividade.
//  * 
//  * DICA: A carga atual muda a cada recarga realizada (ver adicionaEnergiaVeiculo()).
//  */

// #define MAX_PLACA_VEI 8   // tamanho máximo da placa do veículo no padrão AAA0A00 (7) + '\0' 

// typedef struct Veiculo Veiculo;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"

struct Veiculo {
    char placa[MAX_PLACA_VEI];
    int capacidade, carga;
};

/**
 * Cria um veículo a partir dos dados fornecidos.
 *
 * Aloca dinamicamente um Veiculo e copia a placa para dentro dele.
 *
 * @param placa placa do veículo                             
 * @param capacidade Capacidade total da bateria, em kWh (inteiro > 0).
 * @param carga Carga inicial da bateria, em porcentagem (valor de 0 a 100).
 * 
 * @return  Ponteiro para o Veiculo criado;  
 **/
Veiculo *criaVeiculo(char *placa, int capacidade, int carga) {
    Veiculo *v = (Veiculo *) calloc(1, sizeof(Veiculo));
    strcpy(v->placa, placa);
    v->capacidade = capacidade;
    v->carga = carga;
    return v;
}

/**
 * Lê os dados de um veículo da entrada padrão e cria o Veiculo.
 * Lê, na ordem descrita no padrão de entrada, 
 * uma informação por linha (consumindo o '\n' de cada linha):
 * 
 * Dica: para facilitar a sua vida...
 *   scanf("%[^\n]\n", placa);
 *   scanf("%d\n", &capacidade);
 *   scanf("%d\n", &carga);
 * 
 *  
 * @return  Ponteiro para o Veiculo lido.
 **/
Veiculo *lerVeiculo() {
    char placa[MAX_PLACA_VEI];
    int capacidade, carga;
    scanf("%[^\n]\n", placa);
    scanf("%d\n", &capacidade);
    scanf("%d\n", &carga);

    return criaVeiculo(placa, capacidade, carga);
}

/**
 * Retorna a placa do veículo.
 *
 * @param v  Ponteiro para o veículo a consultar (não-nulo).
 * 
 * @return   Ponteiro para a string INTERNA com a placa. 
 */
char *obtemPlacaVeiculo(Veiculo *v) {
    return v->placa;
}

/**
 * Calcula quanta energia, em kWh, falta para a bateria ficar 100% carregada.
 * A regra para cálculo está disponível na descrição da atividade.  
 *
 * @param v  Ponteiro para o veículo a consultar (não-nulo).
 * 
 * @return   Energia faltante em kWh (>= 0). 
 */
int calculaEnergiaFaltanteVeiculo(Veiculo *v) {
    return (v->capacidade*(100 - v->carga)/100);
}

/**
 * Atualiza a carga do veículo após receber energia de uma recarga.
 * A regra para cálculo está disponível na descrição da atividade.
 *
 * @param v  Ponteiro para o veículo a consultar (não-nulo).
 * @param energia Energia recebida, em kWh (>= 0). 
 */
void adicionaEnergiaVeiculo(Veiculo *v, int energia) {
    v->carga += (energia*100)/v->capacidade;
    if(v->carga > 100)
        v->carga = 100;
}

/**
 * Libera toda a memória alocada para um veículo.
 *
 * @param v  Ponteiro para o veículo a consultar. 
 */
void liberaVeiculo(Veiculo *v) {
    free(v);
}
