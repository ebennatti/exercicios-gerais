
// #define MAX_NOME 10 /**< Tamanho máximo do nome da cidade. */

// #define QTD_DEF 10 /**< Quantidade máxima de defesas que uma cidade pode ter. */
// #define QTD_MIS 10 /**< Quantidade máxima de mísseis que uma cidade pode ter. */

// #define ENCERRAR 'F' /**< Caractere que indica o fim da entrada. */
// #define MISSIL 'M' /**< Caractere que indica um míssil. */
// #define DEFESA 'D' /**< Caractere que indica uma defesa. */

// /**
//  * @brief Estrutura que representa uma cidade.
//  * 
//  * A estrutura tCidade contém o nome da cidade, a quantidade de mísseis e defesas, e as listas de mísseis e defesas.
//  * 
//  */
// typedef struct cidade * tCidade;
#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
#include "missil.h"
#include "defesa.h"

struct cidade {
    char nome[MAX_NOME];
    float x, y;
    int qtdMisseis, qtdDefesas;
    tMissil *listaMisseis;
    tDefesa *listaDefesas;
    float ataqueTotal, ataqueSofrido;
};

/**
 * @brief Lê os limites da cidade da entrada padrão e cria uma nova cidade.
 * 
 * @return tCidade Ponteiro para a cidade criada.
 */
tCidade CriaCidade() {
    tCidade c = calloc(1, sizeof(*c));
    c->qtdDefesas = c->qtdMisseis = 0;
    c->listaDefesas = calloc(QTD_DEF, sizeof(*c->listaDefesas));
    c->listaMisseis = calloc(QTD_MIS, sizeof(*c->listaMisseis));
    c->ataqueSofrido = 0;
    c->ataqueTotal = 0;
    scanf("C %f %f\n", &c->x, &c->y);
    return c;
}

/**
 * @brief Lê defesas e mísseis da entrada padrão e os acrescenta à cidade. 
 * Além disso, essa função também é responsável por ler o último caractere da entrada.
 * 
 * @param cidade Ponteiro para a cidade que será preenchida.
 * @return tCidade Ponteiro para a cidade preenchida.
 */
tCidade LeEntrada(tCidade cidade) {
    char c;

    while(scanf("%c", &c) == 1 && c != 'F') {
        if(c == 'M') {
            cidade->listaMisseis[cidade->qtdMisseis] = LeMissil(); 
            cidade->qtdMisseis++;
        } else if(c == 'D') {
            cidade->listaDefesas[cidade->qtdDefesas] = LeDefesa();
            cidade->qtdDefesas++;
        }
    }

    return cidade;
}

/**
 * @brief Imprime as informações da cidade.
 * 
 * @param cidade Ponteiro para a cidade que será impressa.
 */
// void ImprimeCidade(tCidade cidade);

/**
 * @brief Libera a memória alocada para a cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void LiberaCidade(tCidade cidade) {
    for(int i = 0; i < cidade->qtdDefesas; i++) {
        LiberaDefesa(cidade->listaDefesas[i]);
    }
    free(cidade->listaDefesas);

    for(int i = 0; i < cidade->qtdMisseis; i++) {
        LiberaMissil(cidade->listaMisseis[i]);
    }
    free(cidade->listaMisseis);

    free(cidade);
}

/**
 * @brief Processa os ataques na cidade na ordem em que foram cadastrados.
 * 
 * @param cidade Ponteiro para a cidade que será atacada.
 */
void ProcessaAtaques(tCidade cidade) {
    for(int i = 0; i < cidade->qtdMisseis; i++) {
        cidade->ataqueTotal += GetMissilPoder(cidade->listaMisseis[i]);
        for(int j = 0; j < cidade->qtdDefesas; j++) {
            if(VerificaSeDentroArea(cidade->listaDefesas[j], GetMissilX(cidade->listaMisseis[i]), GetMissilY(cidade->listaMisseis[i]))) {
                if(PodeDefender(cidade->listaDefesas[j])) {
                    UsaDefesa(cidade->listaDefesas[j]);
                    ReduzPoder(cidade->listaMisseis[i], GetDefesaPoder(cidade->listaDefesas[j]));
                }
            } 
        }

        if(GetMissilX(cidade->listaMisseis[i]) <= cidade->x && GetMissilY(cidade->listaMisseis[i]) <= cidade->y)
            cidade->ataqueSofrido += GetMissilPoder(cidade->listaMisseis[i]);
    }
}

/**
 * @brief Imprime o relatório final na saída padrão, sem processar ataques.
 * 
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void ImprimeDados(tCidade cidade) {
    for(int i = 0; i < cidade->qtdDefesas; i++) 
        ImprimeDefesa(cidade->listaDefesas[i]);

    for(int i = 0; i < cidade->qtdMisseis; i++)
        ImprimeMissil(cidade->listaMisseis[i]);

    printf("Efetividade: %.2f%%", 100.0*(1.0 - (cidade->ataqueSofrido/cidade->ataqueTotal)));
}