// #ifndef _ARRAY_H_
// #define _ARRAY_H_


// typedef struct Array Array;
#include <stdio.h>
#include <stdlib.h>

#include "array.h"

struct Array {
    int *data, tamanho;  
};

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray() {
    Array *a = (Array *) calloc(1, sizeof(Array));
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
        array->data = (int) realloc(array->data, (array->tamanho + 1)*sizeof(int));
        array->data[array->tamanho] = n;
        array->tamanho++;
    }
    scanf("%*c");
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array) {
    int aux;
    for(int i = 0; i < array->tamanho; i++) {
        for(int j = i + 1; j < array->tamanho; j++) {
            
            if(array->data[j] < array->data[i]) {
                aux = array->data[j];
                array->data[j] = array->data[i];
                array->data[i] = aux;
            }
        }
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado) {
    int inicio = 0, fim = array->tamanho - 1;

    while(inicio <= fim) {
        int idxMeio = inicio + (fim - inicio) / 2;

        if(elementoBuscado < array->data[idxMeio]) {
            fim = idxMeio - 1;
        } else if(elementoBuscado > array->data[idxMeio]) {
            inicio = idxMeio + 1;
        } else {
            return idxMeio;
        }
    }

    return -1;
}