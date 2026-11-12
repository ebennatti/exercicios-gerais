#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tadgen.h"

// typedef enum {
//     FLOAT = 0,
//     INT = 1
// } Type;

struct generic {
    Type t;
    void *dados;
    int qtd;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric *g = (tGeneric *) calloc(1, sizeof(tGeneric));
    g->qtd = numElem;
    g->t = type;
    if(g->t == INT)
        g->dados = (int *) calloc(g->qtd, sizeof(int));
    else if(g->t == FLOAT)
        g->dados = (float *) calloc(g->qtd, sizeof(float)); 

    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen) {
    free(gen->dados);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen) {
    printf("\nDigite o vetor:\n");
    if(gen->t == INT) {
        for(int i = 0; i < gen->qtd; i++) {
            scanf("%d", &((int *)gen->dados)[i]);
        }
    } else if(gen->t == FLOAT) {
        for(int i = 0; i < gen->qtd; i++) {
            scanf("%f", &((float *)gen->dados)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen) {
    if(gen->t == INT) {
        int *vet = (int *)gen->dados;
        for(int i = 0; i < gen->qtd; i++) {
            printf("%d ", vet[i]);
        }
    } else if(gen->t == FLOAT) {
        float *vet = (float *)gen->dados;
        for(int i = 0; i < gen->qtd; i++) {
            printf("%.2f ", vet[i]);
        }
    }

    printf("\n");
}