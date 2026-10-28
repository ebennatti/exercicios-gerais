// #ifndef _agencia
// #define _agencia

// #include "conta.h"

// typedef struct Agencia tAgencia;

#include <stdio.h>
#include <stdlib.h>

#include "agencia.h"
#include "operacao.h"

struct Agencia {
    tConta **listaContas;
    tOperacao **listaOp;
    int qtdContas, qtdOp;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */
tAgencia* CriaAgencia() {
    tAgencia *agencia = (tAgencia *) calloc(1, sizeof(*agencia));
    agencia->listaContas = NULL;
    agencia->listaOp = NULL;

    return agencia;
}

//retorna 1 se existe e 0 caso nao
int idExiste(tAgencia *a, int id, int qtdCadastradas);

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia* agencia) {
    for (int i = 0; i < agencia->qtdContas; i++)
        DestroiConta(agencia->listaContas[i]);
    free(agencia->listaContas);

    for (int i = 0; i < agencia->qtdOp; i++)
        DestroiOperacao(agencia->listaOp[i]);
    free(agencia->listaOp);

    free(agencia);
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro. 
 * Assim como imprime as possíveis mensagens de erro para essa ação.
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia) {
    int qtdContas, qtdOp, id, valor, i = 0;
    scanf("%d", &qtdContas);
    agencia->listaContas = calloc(qtdContas, sizeof(tConta *));
    agencia->qtdContas = qtdContas;
    while(i < qtdContas) {
        scanf("%d", &id);
        if(idExiste(agencia, id, i)) 
            printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
        else {
            if(id > 0) {
                agencia->listaContas[i] = CriaConta(id);
                i++;
            } else 
                printf("\nDigite um id valido para a conta a ser cadastrada!");
        }
    }

    scanf("%d", &qtdOp);
    i = 0;
    agencia->listaOp = calloc(qtdOp, sizeof(tOperacao *));
    agencia->qtdOp = qtdOp;
    while(i < qtdOp) {
        scanf("%d %d", &id, &valor);
        if(idExiste(agencia, id, qtdContas)) {
            AlteraSaldoConta(BuscaContaPorId(agencia, id), valor);
            agencia->listaOp[i] = CriaOperacao(BuscaContaPorId(agencia, id), valor);
            i++;
        } else {
            printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta* BuscaContaPorId(tAgencia *agencia, int id) {
    for(int i = 0; i < agencia->qtdContas; i++) {
        if(ConfereIdConta(agencia->listaContas[i], id))
            return agencia->listaContas[i];
    }

    return NULL;
}

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia* agencia) {
    printf("\nA lista de operações suspeitas:");
    for(int i = 0; i < agencia->qtdOp; i++) {
        if(ConsultaValorOperacao(agencia->listaOp[i]) > 20000 || ConsultaValorOperacao(agencia->listaOp[i]) < -20000)
            ImprimeOperacao(agencia->listaOp[i]);
    }
}

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia) {
    int idx1 = -1, idx2 = -1;

    for(int i = 0; i < agencia->qtdContas; i++) {
        float s = RetornaSaldoConta(agencia->listaContas[i]);
        if(idx1 == -1 || s > RetornaSaldoConta(agencia->listaContas[idx1])) {
            idx2 = idx1;
            idx1 = i;
        } else if(idx2 == -1 || s > RetornaSaldoConta(agencia->listaContas[idx2])) {
            idx2 = i;
        }
    }

    printf("\nOs dois correntistas com maior saldo são:\n");
    if(idx1 != -1)
        printf("Id: %d, Saldo: %.2f\n", RetornaIdConta(agencia->listaContas[idx1]), RetornaSaldoConta(agencia->listaContas[idx1]));
    if(idx2 != -1)
        printf("Id: %d, Saldo: %.2f\n", RetornaIdConta(agencia->listaContas[idx2]), RetornaSaldoConta(agencia->listaContas[idx2]));
}

/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia* agencia) {
    float saldoAgencia = 0;
    for(int i = 0; i < agencia->qtdOp; i++) {
        saldoAgencia += ConsultaValorOperacao(agencia->listaOp[i]);
    }
    printf("O saldo total da agencia eh: %.2f", saldoAgencia);
}

int idExiste(tAgencia *a, int id, int qtdCadastradas) {
    for(int i = 0; i < qtdCadastradas; i++) {
        if(ConfereIdConta(a->listaContas[i], id))
            return 1;
    }

    return 0;
}
