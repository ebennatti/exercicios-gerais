#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define AUMENTO 5

// typedef struct Array {
//     int *data;
//     int tamanho;
// } Array;

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray() {
    Array *a = calloc(1, sizeof(Array));
    a->data = NULL;
    a->tamanho = 0;
    return a;
}


/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array) {
    free(array->data);
    free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array) {
    int n;
    while(scanf("%d", &n) == 1) {
        array->tamanho++;
        array->data = (int) realloc(array->data, array->tamanho*sizeof(int));
        array->data[array->tamanho - 1] = n;
    }
    scanf("%*c");
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array) {
    int menor = 0, idxMenor = -1, aux = 0;
    for(int i = 0; i < array->tamanho; i++) {
        menor = array->data[i];
        idxMenor = i;
        for(int j = i + 1; j < array->tamanho; j++) {
            if(array->data[j] < menor) {
                menor = array->data[j];
                idxMenor = j;
            }
        }

        aux = array->data[i];
        array->data[i] = array->data[idxMenor];
        array->data[idxMenor] = aux;
    }
}   

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado) {
    int inicio = 0;
    int fim = array->tamanho - 1;

    while (inicio <= fim) {
        int idxMeio = inicio + (fim - inicio) / 2;

        if (elementoBuscado < array->data[idxMeio]) {
            fim = idxMeio - 1;
        } else if (elementoBuscado > array->data[idxMeio]) {
            inicio = idxMeio + 1;
        } else {
            return idxMeio;
        }
    }
    return -1;
}