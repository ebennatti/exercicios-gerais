
/**
 * @brief Estrutura que representa uma franquia.
 * 
 * A estrutura franquia contém informações sobre o nome da franquia, sua conferência e seu desempenho em casa e fora.
 * 
 */
// typedef struct franquia * tFranquia;
// struct franquia{
// 	char * nome;
// 	char * conferencia;
// 	int vit_casa, vit_fora;
// 	int der_casa, der_fora;
// 	float aproveitamento;
// };

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "franquia.h"

// #define MAX_NOME 32

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 * 
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia() {
	tFranquia f = calloc(1, sizeof(*f));
	f->nome = calloc(MAX_NOME, sizeof(char));
	f->conferencia = calloc(MAX_NOME, sizeof(char));
	f->vit_casa = 0;
	f->vit_fora = 0;
	f->der_casa = 0;
	f->der_fora = 0;
	scanf(" %s %s\n", f->nome, f->conferencia);
	return f;
}

/**
 * @brief Libera a memória alocada para uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f) {
	free(f->conferencia);
	free(f->nome);
	free(f);
}

/**
 * @brief Imprime as informações de uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f) {
	//número  de  vitórias  da  franquia,  número  de  derrotas  da  franquia,  %  de 
	//aproveitamento  de  vitória,  número  de  vitórias  em  casa,  número  de  vitórias  fora  de  casa

	printf("%s ", f->nome);
	if(!strcmp(f->conferencia, "LESTE"))
		printf("[CL] ");
	else 
		printf("[CO] ");
	if((f->vit_casa + f->vit_fora + f->der_casa + f->der_fora))
		printf("%d %d %.2f %d %d\n", (f->vit_casa + f->vit_fora), (f->der_casa + f->der_fora),
		100.0*((f->vit_fora + f->vit_casa)/(float) (f->vit_casa + f->vit_fora + f->der_casa + f->der_fora)), f->vit_casa, f->vit_fora);
	else 
		printf("%d %d 0.00 %d %d\n", (f->vit_casa + f->vit_fora), (f->der_casa + f->der_fora), f->vit_casa, f->vit_fora);
}

/**
 * @brief Retorna o nome da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char * GetNomeFranquia(tFranquia f) {
	return f->nome;
}

/**
 * @brief Retorna a conferência da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char * GetConferenciaFranquia(tFranquia f) {
	return f->conferencia;
}

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f) {
	f->vit_casa++;
}

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franq06_alocacao_dinamica/02_TAD_dinamico/TAD_pont_14/Includes/franquia.huia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f) {
	f->vit_fora++;
}

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f) {
	f->der_casa++;
}

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f) {
	f->der_fora++;
}

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f) {
	return f->vit_casa;
}

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f) {
	return f->vit_fora;
}

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f) {
	return f->der_casa;
}

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f) {
	return f->der_fora;
}