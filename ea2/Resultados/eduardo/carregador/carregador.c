
// #ifndef _CARREGADOR_H
// #define _CARREGADOR_H

// /*
//  * TAD Carregador
//  * --------------
//  * Representa um carregador (equipamento) instalado em uma estação utilizando as 
//  * informações descritas no enunciado da atividade.
//  *
//  * Dica: o carregador NÃO guarda os veículos que recarregou: o veículo é apenas usado
//  * durante realizaRecargaCarregador() e continua pertencendo a quem o criou.
//  */

// #include "veiculo.h"

// #define MAX_COD_EST_CAR   9   // tamanho máximo do código da estação no padrão EST-0000 (8) + '\0' 
// #define MAX_ID_CAR       11   // tamanho máximo do identificador do carregador (até 10) + '\0'      

// typedef struct Carregador Carregador;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "carregador.h"

struct Carregador {
    char id[MAX_ID_CAR], codEstacao[MAX_COD_EST_CAR];
    int potencia, preco, tempoMax, recCompletas, recParciais, energiaEntregue, tempoPerm;
};

/**
 * Cria um carregador sem nenhuma recarga realizada. *
 * Aloca dinamicamente um Carregador e copia as strings codEstacao e id
 * para dentro dele. 
 *
 * @param codEstacao Código da estação à qual o carregador pertence *                   
 * @param id         Identificador único do carregador
 * @param potencia   Potência do carregador, em kW (> 0).
 * @param preco      Preço cobrado por kWh entregue, em R$ (>= 0).
 * @param tempoMax   Tempo máximo de uma recarga, em minutos (>= 0).
 *
 * @return  Ponteiro para o Carregador criado; 
 */
Carregador *criaCarregador(char *codEstacao, char *id, int potencia, int preco, int tempoMax) {
    Carregador *c = (Carregador *) calloc(1, sizeof(Carregador));
    strcpy(c->codEstacao, codEstacao);
    strcpy(c->id, id);
    c->potencia = potencia;
    c->preco = preco;
    c->tempoMax = tempoMax;
    c->recCompletas = 0;
    c->recParciais = 0;
    c->energiaEntregue = 0;
    c->tempoPerm = 0;

    return c;
}

/**
 * Lê os dados de um carregador da entrada padrão e cria o Carregador.
 * Lê, na ordem descrita no padrão de entrada, 
 * uma informação por linha (consumindo o '\n' de cada linha):
 * 
 * Dica: para facilitar a sua vida...
 *   scanf("%[^\n]\n", codEstacao);
 *   scanf("%[^\n]\n", id);
 *   scanf("%d\n", &potencia);
 *   scanf("%d\n", &preco);
 *   scanf("%d\n", &tempoMax);
 *
 * @return  Ponteiro para o Carregador lido
 */
Carregador *lerCarregador() {
    char id[MAX_ID_CAR], codEstacao[MAX_COD_EST_CAR];
    int potencia, preco, tempoMax;

    scanf("%[^\n]\n", codEstacao);
    scanf("%[^\n]\n", id);
    scanf("%d\n", &potencia);
    scanf("%d\n", &preco);
    scanf("%d\n", &tempoMax);

    return criaCarregador(codEstacao, id, potencia, preco, tempoMax);
}

/**
 * Retorna o código da estação à qual o carregador pertence.
 *
 * @param c  Ponteiro para o Carregador a consultar (não-nulo).
 * @return   Ponteiro para a string INTERNA com o código da estação.
 */
char *obtemCodEstacaoCarregador(Carregador *c) {
    return c->codEstacao;
}

/**
 * Retorna o identificador do carregador.
 *
 * @param c  Ponteiro para o Carregador a consultar (não-nulo).
 * @return   Ponteiro para a string INTERNA com o identificador. 
 */
char *obtemIdCarregador(Carregador *c) {
    return c->id;
}

/**
 * Realiza a recarga de um veículo neste carregador.
 * As regras para cálculos estão disponíveis na descrição da atividade.
 *
 * @param c  Ponteiro para o Carregador onde a recarga é feita (não-nulo).
 * @param v  Ponteiro para o Veículo recarregado (não-nulo). 
 *           Importante: o Veículo tem o valor de sua carga atualizada;
 *  *
 * @return  1 se a recarga foi COMPLETA; 0 se foi PARCIAL.
 */
int realizaRecargaCarregador(Carregador *c, Veiculo *v) {
    //Tempo necessário (min) = energia faltante × 60 / potência do carregador
    int tempNec = (calculaEnergiaFaltanteVeiculo(v)*60)/c->potencia;
    if(tempNec <= c->tempoMax) {
        c->recCompletas++;
        c->tempoPerm += tempNec;
        c->energiaEntregue += calculaEnergiaFaltanteVeiculo(v);
        adicionaEnergiaVeiculo(v, calculaEnergiaFaltanteVeiculo(v));
        return 1;
    } else {
        c->recParciais++;
        c->tempoPerm += c->tempoMax;
        c->energiaEntregue += ((c->potencia*c->tempoMax)/60);
        adicionaEnergiaVeiculo(v, ((c->potencia * c->tempoMax)/60));
        return 0;
    }
}

/**
 * Retorna quantas recargas foram realizadas neste carregador.
 * @param c  Ponteiro para o Carregador a consultar (não-nulo).
 *
 * @return   Quantidade de recargas. 
 */
int obtemNumRecargasCarregador(Carregador *c) {
    return (c->recCompletas + c->recParciais);
}

/**
 * Retorna quantas das recargas realizadas neste carregador foram completas.
 * @param c  Ponteiro para o Carregador a consultar (não-nulo).
 * 
 * @return   Quantidade de recargas completas. 
 */
int obtemNumRecargasCompletasCarregador(Carregador *c) {
    return c->recCompletas;
}

/**
 * Retorna a soma da energia entregue em todas as recargas deste carregador.
 * @param c  Ponteiro para o Carregador a consultar (não-nulo).
 * @return   Energia total em kWh (>= 0);
 */
int obtemEnergiaCarregador(Carregador *c) {
    return c->energiaEntregue;
}

/**
 * Retorna a soma dos valores cobrados em todas as recargas deste carregador.
 * @param c  Ponteiro para o Carregador a consultar (não-nulo).
 * @return   Faturamento total em R$ (>= 0);
 * @pre      c != NULL.
 */
int obtemFaturamentoCarregador(Carregador *c) {
    return (c->energiaEntregue * c->preco);
}

/**
 * Imprime a linha de faturamento do carregador no relatório COMPLETO
 * de acordo com o padrão de saída.
 * Carregadores sem recargas imprimem "R$ 0".
 * 
 * Dica: para facilitar a sua vida...
 * printf("-- %s: R$ %d\n", id, (int) faturamento);
 *
 * @param c  Ponteiro para o Carregador a imprimir (não-nulo). 
 */
void imprimeFaturamentoCarregador(Carregador *c) {
    printf("-- %s: R$ %d\n", c->id, obtemFaturamentoCarregador(c));
}

/**
 * Libera toda a memória alocada para um carregador.
 *
 * @param c  Ponteiro para o Carregador a liberar. 
 */
void liberaCarregador(Carregador *c) {
    free(c);
}
