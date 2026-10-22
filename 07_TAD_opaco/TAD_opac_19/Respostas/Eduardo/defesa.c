

// #define QUADRADO 'Q' /**< Caractere que indica uma defesa do tipo quadrado. */
// #define CIRCULO 'C' /**< Caractere que indica uma defesa do tipo círculo. */
// #define MAX_TAM 100 /**< Tamanho máximo do nome da defesa. */

// /**
//  * @brief Estrutura que representa uma defesa.
//  * 
//  * A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho e o poder de defesa.
//  * 
//  */
// typedef struct defesa * tDefesa;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "defesa.h"

struct defesa {
    char nome[MAX_TAM], tipo;
    float x, y, tamanho, poder;
    int qtd;
};

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 * 
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa() {
    //D1 30.0 30.0 Q 28.30 50.3 4
    tDefesa d = calloc(1, sizeof(*d));
    scanf(" %s %f %f %c %f %f %d\n", d->nome, &d->x, &d->y, &d->tipo, &d->tamanho, &d->poder, &d->qtd);
    return d;
}

/**
 * @brief Imprime as informações da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa) {
    printf("D-%s: %d\n", defesa->qtd);
}

/**
 * @brief Libera a memória alocada para a defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa) {
    free(defesa);
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y) {
    if(defesa->tipo == 'C') {
        
    }
}

/**
 * @brief Consome uma unidade de míssil da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa);

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa);

/**
 * @brief Verifica exclusivamente se a quantidade de munição é maior que zero.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa);