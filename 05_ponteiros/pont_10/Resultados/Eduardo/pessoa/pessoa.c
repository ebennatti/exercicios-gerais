#include <stdio.h>
#include <string.h>
#include "pessoa.h"


// typedef struct Pessoa tPessoa;

// struct Pessoa{
//     char nome[100];
//     tPessoa *pai;
//     tPessoa *mae;
//     tPessoa *irmao;
// };

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa() {
     tPessoa p;
    p.nome[0] = '\0';
    p.mae = NULL;
    p.pai = NULL;
    p.irmao = NULL;
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
        // NOME COMPLETO: Maria Rodrigues
        // PAI: Joao Rodrigues
        // MAE: Laura Rodrigues
        // IRMAO: Mariana Rodrigues
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

        if(!pessoa->irmao) {
            printf("IRMAO: NAO INFORMADO\n");
        } else {
            printf("IRMAO: %s\n", pessoa->irmao->nome);
        }
        printf("\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    if(pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai)
        return 1;
    return 0;
}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas) {
    int nAssociacoes;
    scanf("%d", &nAssociacoes);

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

    for(int i = 0; i < numPessoas; i++) {
        for(int j = i + 1; j < numPessoas; j++) {
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) && pessoas[i].irmao == NULL && pessoas[j].irmao == NULL) {
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}