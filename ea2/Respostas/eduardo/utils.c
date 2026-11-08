// #ifndef _UTILS_H
// #define _UTILS_H

// /*
//  * Módulo Utils
//  * ------------------
//  * Reúne as operações que coordenam os TADs Estacao, Carregador e Veiculo entre si.
//  * Não é um TAD: não guarda dados próprios, apenas opera sobre os arrays recebidos.
//  */

// #include "estacao.h"
// #include "carregador.h"
// #include "veiculo.h"

#include <stdio.h>
#include <string.h>

#include "utils.h"

/**
 * Insere o carregador na estação cujo código é igual ao código de estação do carregador.
 * Se a estação não for encontrada, o carregador é liberado.
 *
 * @param ests     Array de ponteiros para as estações cadastradas.
 * @param tamEsts  Quantidade de estações no array.
 * @param car      Ponteiro para o Carregador a inserir (não-nulo).
 */
void insereCarregadorEstacoes(Estacao **ests, int tamEsts, Carregador *car) {
    for(int i = 0; i < tamEsts; i++) {
        if(!strcmp(obtemCodEstacaoCarregador(car), obtemCodigoEstacao(ests[i]))) {
            adicionaCarregadorEstacao(ests[i], car);
            return;
        }
    }

    liberaCarregador(car);
}

/**
 * Busca um veículo pela placa.
 *
 * @param veis     Array de ponteiros para os veículos cadastrados.
 * @param tamVeis  Quantidade de veículos no array.
 * @param placa    Placa do veículo procurado.
 * @return         Ponteiro para o Veiculo encontrado; NULL caso não exista.
 */
Veiculo *buscaVeiculo(Veiculo **veis, int tamVeis, char *placa) {
    for(int i = 0; i < tamVeis; i++) {
        if(!strcmp(obtemPlacaVeiculo(veis[i]), placa)) {
            return veis[i];
        }
    }

    return NULL;
}

/**
 * Busca um carregador pelo identificador em todas as estações.
 *
 * @param ests     Array de ponteiros para as estações cadastradas.
 * @param tamEsts  Quantidade de estações no array.
 * @param id       Identificador do carregador procurado.
 * @return         Ponteiro para o Carregador encontrado; NULL caso não exista.
 */
Carregador *buscaCarregador(Estacao **ests, int tamEsts, char *id) {
    for(int i = 0; i < tamEsts; i++) {
        if(buscaCarregadorEstacao(ests[i], id)) {
            return buscaCarregadorEstacao(ests[i], id);
        }
    }

    return NULL;
}

/**
 * Lê da entrada padrão a placa do veículo e o identificador do carregador
 * (uma informação por linha) e realiza a recarga.
 * Se o veículo ou o carregador não existirem, a recarga é ignorada.
 *
 * @param ests     Array de ponteiros para as estações cadastradas.
 * @param tamEsts  Quantidade de estações no array.
 * @param veis     Array de ponteiros para os veículos cadastrados.
 * @param tamVeis  Quantidade de veículos no array.
 */
void realizaRecarga(Estacao **ests, int tamEsts, Veiculo **veis, int tamVeis) {
    char placa[MAX_PLACA_VEI], idcarregador[MAX_ID_CAR];
    scanf("%[^\n]\n", placa);
    scanf("%[^\n]\n", idcarregador);
    
    if(buscaCarregador(ests, tamEsts, idcarregador) && buscaVeiculo(veis, tamVeis, placa))
        realizaRecargaCarregador(buscaCarregador(ests, tamEsts, idcarregador), buscaVeiculo(veis, tamVeis, placa));
        
}
