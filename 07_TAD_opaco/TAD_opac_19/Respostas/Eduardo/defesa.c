

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
    printf("D-%s: %d\n", defesa->nome, defesa->qtd);
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
    float distx = fabs((x - defesa->x)), disty = fabs((y - defesa->y));
    if(defesa->tipo == 'C') {
        float dist = sqrt(pow(distx, 2) + pow(disty, 2));
        if(dist < defesa->tamanho)
            return 1;
        else
            return 0;
    } else if(defesa->tipo == 'Q') {
        float lado = sqrt(pow((2*defesa->tamanho), 2)/2.0);
        float supEsqx = defesa->x - lado/2, supesqy = defesa->y + lado/2;
        float infDirx = defesa->x + lado/2, infDiry = defesa->y - lado/2;
        if(x > supEsqx && x < infDirx && y > infDiry && y < supesqy)
            return 1;
        else
            return 0;
    }
}

/**
 * @brief Consome uma unidade de míssil da defesa.
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa) {
    defesa->qtd--;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa) {
    return defesa->poder;
}

/**
 * @brief Verifica exclusivamente se a quantidade de munição é maior que zero.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa) {
    return (defesa->qtd > 0);
}