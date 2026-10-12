#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao() {
    char *vet = calloc(TAM_PADRAO + 1, sizeof(char));

    for(int i = 0; i < TAM_PADRAO + 1; i++) {
        if(i < TAM_PADRAO)
            vet[i] = '_';
        else
            vet[i] = '\0';
    }

    return vet;
}

char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    int novotamanho = tamanhoantigo + TAM_PADRAO;

    char *tmp = realloc(vetor, (novotamanho + 1) * sizeof *vetor);
    if (tmp == NULL) {
        free(vetor);
        exit(1);
    }
    vetor = tmp;

    for (int i = tamanhoantigo; i < novotamanho; i++) {
        vetor[i] = '_';
    }
    vetor[novotamanho] = '\0';

    return vetor;
}

char *LeVetor(char *vetor, int *tamanho) {
    char c;
    int i = 0;

    while (scanf("%c", &c) == 1 && c != '\n') {
        if (i >= *tamanho) {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
        vetor[i++] = c;
    }

    return vetor;
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser imprimido.
*/
void ImprimeString(char *vetor) {
    printf("%s\n", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor) {
    free(vetor);
}
