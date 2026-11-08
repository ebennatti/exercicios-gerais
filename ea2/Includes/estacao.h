
#ifndef _ESTACAO_H
#define _ESTACAO_H

/*
 * TAD Estacao
 * -----------
 * Representa uma estação de recarga de veículos elétricos no sistema utilizando as 
 * informações descritas no enunciado da atividade.
 *
 *
 * Dica: A Estacao é DONA de todos os carregadores adicionados a ela.
 * Energia e faturamento são somados em int.
 */

#include "carregador.h"

#define MAX_NOME_EST   101   // tamanho máximo do nome da estação (até 100) + '\0'               
#define MAX_COD_EST      9   // tamanho máximo do  código no padrão EST-0000 (8) + '\0'           
#define MAX_CIDADE_EST  51   // tamanho máximo da cidade (até 50) + '\0'                        

typedef struct Estacao Estacao;

/**
 * Cria uma estação sem carregadores.
 * Aloca dinamicamente a Estacao, copia as strings recebidas.
 *
 * @param nome      Nome da estação
 * @param codigo    Código único da estação
 * @param cidade    Cidade da estação
 * @param aberta24h 'S' se a estação funciona 24 horas; 'N' caso contrário.
 *
 * @return  Ponteiro para a Estacao criada;
 */
Estacao *criaEstacao(char *nome, char *codigo, char *cidade, char aberta24h);

/**
 * Lê os dados de uma estação da entrada padrão e cria a Estacao.
 * Lê, na ordem descrita no padrão de entrada, 
 * uma informação por linha (consumindo o '\n' de cada linha):
 * 
 * Dica: para facilitar a sua vida...
 *  scanf("%[^\n]\n", nome);
 *  scanf("%[^\n]\n", codigo);
 *  scanf("%[^\n]\n", cidade);
 *  scanf("%c\n", &aberta24h);
 *
 * @return  Ponteiro para a Estacao lida
 */
Estacao *lerEstacao();

/**
 * Adiciona um carregador ao final da lista de carregadores da estação.
 * Realiza todo o gerenciamento de memória necessário para manter a lista de carregadores.
 * Incluindo alocação, realocação, liberação de memória e quantidade de itens.  
 *
 * Importante: a função NÃO verifica se o código de estação do carregador coincide
 *          com o da estação; essa verificação é responsabilidade do chamador da função.
 * 
 * @param e  Ponteiro para a Estação que receberá o carregador (não-nulo).
 * @param c  Ponteiro para o Carregador a adicionar (não-nulo). A estação passa
 *                            a ser dona do ponteiro e o liberará em liberaEstacao(). 
 */
void adicionaCarregadorEstacao(Estacao *e, Carregador *c);

/**
 * Retorna o código da estação.
 *
 * @param e  Ponteiro para a Estação a consultar (não-nulo).
 * @return   Ponteiro para a string INTERNA com o código. 
 */
char *obtemCodigoEstacao(Estacao *e);

/**
 * Retorna quantos carregadores foram adicionados à estação.
 *
 * @param e  Ponteiro para a Estação a consultar (não-nulo).
 * @return   Valor de nCarregadores (>= 0). 
 */
int obtemNumCarregadoresEstacao(Estacao *e);

/**
 * Procura, entre os carregadores da estação, aquele com o identificador dado.
 *
 * @param e   Ponteiro para a Estação onde procurar (não-nulo).
 * @param id  String com o identificador do carregador procurado.
 *
 * @return  Ponteiro para o Carregador da lista cujo identificador é igual a id;
 *          NULL se nenhum carregador da estação tiver esse identificador. 
 */
Carregador *buscaCarregadorEstacao(Estacao *e, char *id);

/**
 * Soma a quantidade de recargas realizadas nos carregadores da estação.
 * 
 * @param e  Ponteiro para a Estação a consultar (não-nulo).
 * @return   Soma total de recargas considerando todos os carregadores da estação (>= 0).
 */
int qtdRecargasEstacao(Estacao *e);

/**
 * Soma a quantidade de recargas completas nos carregadores da estação.
 * 
 * @param e  Ponteiro para a Estação a consultar (não-nulo).
 * @return   Soma total de recargas completas considerando todos os carregadores da estação (>= 0). 
 */
int qtdRecargasCompletasEstacao(Estacao *e);

/**
 * Soma a energia entregue (kWh) por todos os carregadores da estação.
 * 
 * @param e  Ponteiro para a Estação a consultar (não-nulo).
 * @return   Soma total de energia considerando todos os carregadores da estação (>= 0). 
 */
int calculaEnergiaEstacao(Estacao *e);

/**
 * Soma o faturamento (R$) de todos os carregadores da estação.
 * @param e  Ponteiro para a Estação a consultar (não-nulo).
 * @return   Soma total de faturamento considerando todos os carregadores da estação (>= 0). 
 */
int calculaFaturamentoEstacao(Estacao *e);

/**
 * Imprime o bloco de faturamento da estação no relatório COMPLETO
 * de acordo com o padrão de saída, por exemplo:
 * - ELETROPOSTO PRAIA DO CANTO: R$ 234
 *  -- C1: R$ 47
 *  -- C3: R$ 187
 *
 *  - RECARGA RAPIDA SUL: R$ 24
 *  -- C7: R$ 24
 *
 * @param e  Ponteiro para a Estação a imprimir (não-nulo). 
 */
void imprimeFaturamentoEstacao(Estacao *e);

/**
 * Libera toda a memória da estação, incluindo todos os carregadores adicionados a ela.
 * 
 * @param e  Ponteiro para a Estação a liberar
 */
void liberaEstacao(Estacao *e);

#endif
