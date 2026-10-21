
// struct partida{
// 	char * time1;
// 	char * time2;
// 	int pontos1, pontos2;
// };

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partida.h"

// /**
//  * @brief Constante que representa o time da casa.
//  * 
//  */
// #define TIME_CASA 1

// /**
//  * @brief Constante que representa o time visitante.
//  * 
//  */
// #define TIME_FORA 2

// /**
//  * @brief Estrutura que representa uma partida.
//  * 
//  * A estrutura partida contém informações sobre os times que jogaram e o vencedor da partida.
//  * 
//  */
// typedef struct partida * tPartida;

#define MAX_NOME 32

/**
 * @brief Lê uma partida do teclado.
 * 
 * @return tPartida Retorna um ponteiro para a partida lida.
 */
tPartida LePartida() {
	tPartida p = calloc(1, sizeof(*p));
	p->time1 = calloc(MAX_NOME, sizeof(char));
	p->time2 = calloc(MAX_NOME, sizeof(char));
	scanf(" %s @ %s %d %d\n", p->time1, p->time2, &p->pontos1, &p->pontos2);
	return p;
}

/**
 * @brief Libera a memória alocada para uma partida.
 * 
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida p) {
	free(p->time1);
	free(p->time2);
	free(p);
}

/**
 * @brief Imprime as informações de uma partida.
 * 
 * @param p Ponteiro para a partida a ser impressa.
 */
void ImprimePartida(tPartida p);

/**
 * @brief Retorna o nome do time da casa.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time da casa.
 */
char * GetTime1Partida(tPartida p) {
	return p->time1;
}

/**
 * @brief Retorna o nome do time visitante.
 * 
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time visitante.
 */
char * GetTime2Partida(tPartida p) {
	return p->time2;
}

/**
 * @brief Retorna o vencedor da partida.
 * 
 * @param p Ponteiro para a partida.
 * @return int Retorna a constante que representa o vencedor da partida (TIME_CASA ou TIME_FORA).
 */
int GetVencedorPartida(tPartida p) {
	if(p->pontos1 > p->pontos2)
		return 1;
	else	
		return 2;
}