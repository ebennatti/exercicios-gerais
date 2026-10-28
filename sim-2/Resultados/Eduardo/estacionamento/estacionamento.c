// #ifndef _ESTACIONAMENTO_H
// #define _ESTACIONAMENTO_H


// #include "veiculo.h"
// #include "datahora.h"

// typedef struct Estacionamento Estacionamento;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estacionamento.h"

struct Estacionamento {
    Veiculo **veiculos;
    int qtdVeiculos;
};

/**
 * @brief   Cria um estacionamento vazio (nenhum veículo registrado).
 *
 *
 * @return  Ponteiro para o Estacionamento criado; NULL se a alocação falhar.
 * @post    O chamador é dono do estacionamento e deve liberá-lo com
 *          liberaEstacionamento().
 */
Estacionamento *criaEstacionamento() {
    Estacionamento *e = (Estacionamento *) calloc(1, sizeof(Estacionamento));
    e->veiculos = NULL;
    e->qtdVeiculos = 0;
    return e;
}

/**
 * @brief   Registra a entrada de um veículo no estacionamento.
 *
 * O veículo é inserido no estacionamento considerando todo gerenciamento de memória necessário.
 *
 * @param e  [entrada/saída]  Estacionamento (não-nulo).
 * @param v  [entrada]        Veículo que está entrando (não-nulo, no pátio). O
 *                            Estacionamento passa a ser DONO do ponteiro.
 *
 * @pre     Não existe no estacionamento outro veículo com a mesma placa
 *          (a função NÃO verifica duplicidade).
 * @post    getTotalEntradasEstacionamento(e) aumenta em 1.
 */
void registraEntradaEstacionamento(Estacionamento *e, Veiculo *v) {
    e->veiculos = (Veiculo **) realloc(e->veiculos, (e->qtdVeiculos + 1)*sizeof(Veiculo *));
    e->veiculos[e->qtdVeiculos] = v;
    e->qtdVeiculos++;
}

/**
 * @brief   Registra a saída do veículo de placa informada.
 *
 * Procura, na lista do estacionamento, o veículo cuja placa é IGUAL a placa
 * (comparação exata de strings) E que ainda está no pátio.
 *   - Se encontrar, registra nele a data/hora de saida (registraSaidaVeiculo()).
 *   - Se NÃO encontrar (placa nunca entrou, ou o veículo dessa placa já saiu), a
 *     saída é IGNORADA e nada é alterado.
 *
 * @param e      [entrada/saída]  Estacionamento (não-nulo).
 * @param placa  [entrada]        Placa do veículo que está saindo.
 * @param saida  [entrada]        Data/hora de saída (não-nula).
 *
 * @return  1 se a saída foi registrada; neste caso o veículo passa a ser DONO de
 *            saida (o chamador NÃO deve liberá-lo);
 *          0 se a saída foi ignorada; neste caso o chamador CONTINUA dono de saida
 *            e é responsável por liberá-lo com liberaDataHora().
 */
int registraSaidaEstacionamento(Estacionamento *e, char *placa, DataHora *saida) {
    for(int i = 0; i < e->qtdVeiculos; i++) {
        if(!strcmp(placa, getPlacaVeiculo(e->veiculos[i])) && estaNoPatioVeiculo(e->veiculos[i])) {
            registraSaidaVeiculo(e->veiculos[i], saida);
            return 1;
        }
    }

    return 0;

}

/**
 * @brief   Retorna a quantidade total de entradas registradas.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Número de veículos registrados (estejam no pátio ou não).
 */
int getTotalEntradasEstacionamento(Estacionamento *e) {
    return e->qtdVeiculos;
}

/**
 * @brief   Retorna a quantidade de saídas registradas (veículos que já saíram).
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Número de veículos cuja saída foi registrada (saídas ignoradas não contam).
 */
int getTotalSaidasEstacionamento(Estacionamento *e) {
    int saidas = 0;
    for(int i = 0; i < e->qtdVeiculos; i++) {
        if(!estaNoPatioVeiculo(e->veiculos[i]))
            saidas++;
    }

    return saidas;
}

/**
 * @brief   Retorna a quantidade de veículos que ainda estão no pátio (ocupação).
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Número de veículos registrados cuja saída ainda não foi registrada.
 */
int getTotalNoPatioEstacionamento(Estacionamento *e) {
    int patio = 0;
    for(int i = 0; i < e->qtdVeiculos; i++) {
        if(estaNoPatioVeiculo(e->veiculos[i]))
            patio++;
    }

    return patio;
}

/**
 * @brief   Soma o tempo de permanência de todos os veículos que já saíram.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Soma, em minutos, de calculaPermanenciaVeiculo() de todos os veículos
 *          registrados (veículos no pátio contribuem com 0). 0 se não houver saídas.
 */
int calculaPermanenciaTotalEstacionamento(Estacionamento *e) {
    int tempo = 0;
    for(int i = 0; i < e->qtdVeiculos; i++) {
        tempo += calculaPermanenciaVeiculo(e->veiculos[i]);
    }

    return tempo;
}

/**
 * @brief   Calcula o faturamento total do estacionamento.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 * @return  Soma, em reais inteiros, de calculaTarifaVeiculo() de todos os veículos
 *          registrados (veículos no pátio contribuem com 0).
 */
int calculaFaturamentoEstacionamento(Estacionamento *e) {
    int faturamento = 0;
    for(int i = 0; i < e->qtdVeiculos; i++) {
        faturamento += calculaTarifaVeiculo(e->veiculos[i]);
    }

    return faturamento;
}

/**
 * @brief   Imprime os veículos que ainda estão no pátio.
 *
 * Percorre a lista na ORDEM DE ENTRADA e chama imprimeVeiculo() para cada veículo
 * que ainda está no pátio (os que já saíram não são impressos). Não imprime nenhum
 * cabeçalho: se não houver veículos no pátio, nada é impresso.
 *
 * @param e  [entrada]  Estacionamento (não-nulo).
 */
void imprimeVeiculosNoPatioEstacionamento(Estacionamento *e) {
    for(int i = 0; i < e->qtdVeiculos; i++) {
        if(estaNoPatioVeiculo(e->veiculos[i]))
            imprimeVeiculo(e->veiculos[i]);
    }
}

/**
 * @brief   Libera toda a memória associada ao estacionamento.
 *
 * Libera cada veículo registrado no estacionamento.
 * @param e  [entrada]  Estacionamento a liberar.
 * @post    e e todos os veículos que ele possuía não devem mais ser usados.
 */
void liberaEstacionamento(Estacionamento *e) {
    for(int i = 0; i < e->qtdVeiculos; i++) {
        liberaVeiculo(e->veiculos[i]);
    }
    free(e->veiculos);

    free(e);
}