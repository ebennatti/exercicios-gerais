#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

// typedef struct Pessoa tPessoa;

// struct Pessoa{
//     char nome[100];
//     tPessoa *pai;
//     tPessoa *mae;
// };

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa() {
    tPessoa p;
    p.nome[0] = '\0';
    p.mae = NULL;
    p.pai = NULL;
    return p;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa) {
    scanf(" %[^\n]", pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    if(pessoa->mae == NULL && pessoa->pai == NULL) {
        return 0;
    } 
    return 1;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa) {
    if(VerificaSeTemPaisPessoa(pessoa)) {
        // NOME COMPLETO: Maria Silva
        // PAI: Luiz Silva
        // MAE: NAO INFORMADO
        if(pessoa->mae && pessoa->pai) {
            printf("NOME COMPLETO: %s\n", pessoa->nome);
            printf("PAI: %s\n", pessoa->pai->nome);
            printf("MAE: %s\n", pessoa->mae->nome);

        } else if(pessoa->mae && !pessoa->pai) {
            printf("NOME COMPLETO: %s\n", pessoa->nome);
            printf("PAI: NAO INFORMADO\n");
            printf("MAE: %s\n", pessoa->mae->nome);

        } else if(!pessoa->mae && pessoa->pai) {
            printf("NOME COMPLETO: %s\n", pessoa->nome);
            printf("PAI: %s\n", pessoa->pai->nome);
            printf("MAE: NAO INFORMADO\n");
        }
        printf("\n");
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int nAssociacoes;
    scanf("%d", &nAssociacoes);

    //mae: 2, pai: -1, filho: 14
    int idxMae, idxPai, idxFilho;
    for(int i = 0; i < nAssociacoes; i++) {
        scanf(" mae: %d, pai: %d, filho: %d", &idxMae, &idxPai, &idxFilho);
        if(idxPai >= 0 && idxMae >= 0 && idxFilho >= 0) {
            pessoas[idxFilho].mae = &pessoas[idxMae];
            pessoas[idxFilho].pai = &pessoas[idxPai];

        } else if(idxPai >= 0 && idxMae < 0 && idxFilho >= 0) {
            pessoas[idxFilho].pai = &pessoas[idxPai];

        } else if(idxPai < 0 && idxMae >= 0 && idxFilho >= 0) {
            pessoas[idxFilho].mae = &pessoas[idxMae];
        }
    }
}