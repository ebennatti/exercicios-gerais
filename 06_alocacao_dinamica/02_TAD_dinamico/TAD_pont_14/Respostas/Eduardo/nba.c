#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "franquia.h"
#include "partida.h"
#include "nba.h"

#define MAX_FR 30 // Número máximo de franquias
#define MAX_PT 82 // Número máximo de partidas
#define CAD_FRANQUIA 'F' // Caractere para cadastro de franquia
#define CAD_PARTIDA 'P' // Caractere para cadastro de partida
#define ENCERRAR 'E' // Caractere para encerrar a NBA


// typedef struct nba * tNBA;
// struct nba{
// 	tFranquia * listafranquias;
// 	int qtdfranquias, maxfranquias;
	
// 	tPartida * listapartidas;
// 	int qtdpartidas, maxpartidas;
// };

/**
 * @brief Cria uma nova instância da NBA.
 * 
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA() {
	tNBA n = calloc(1, sizeof(*n));
	n->listafranquias = calloc(MAX_FR, sizeof(tFranquia));
	n->qtdfranquias = 0;
	n->maxfranquias = MAX_FR;
	n->listapartidas = calloc(MAX_PT, sizeof(tPartida));
	n->qtdpartidas = 0;
	n->maxpartidas = MAX_PT;
}

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 * 
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba) {
	char op = '0';

	while(scanf("%c", &op) == 1 && op != 'E') {
		if(op == 'F' && nba->qtdfranquias < nba->maxfranquias) {
			nba->listafranquias[nba->qtdfranquias] = LeFranquia();
			nba->qtdfranquias++;
		} else if(op == 'P' && nba->qtdpartidas < nba->maxpartidas) {
			nba->listapartidas[nba->qtdpartidas] = LePartida();
			nba->qtdpartidas++;
		}
	}

	for(int i = 0; i < nba->qtdpartidas; i++) {
		int vencedor = GetVencedorPartida(nba->listapartidas[i]);

		for(int j = 0; j < nba->qtdfranquias; j++) {
			if(vencedor == 1) {
				if(!strcmp(GetTime1Partida(nba->listapartidas[i]), GetNomeFranquia(nba->listafranquias[j]))) {
					AdicionaVitoriaCasaFranquia(nba->listafranquias[j]);
				} else if(!strcmp(GetTime2Partida(nba->listapartidas[i]), GetNomeFranquia(nba->listafranquias[j]))) {
					AdicionaDerrotaForaFranquia(nba->listafranquias[j]);
				}
			} else if(vencedor == 2) {
				if(!strcmp(GetTime2Partida(nba->listapartidas[i]), GetNomeFranquia(nba->listafranquias[j]))) {
					AdicionaVitoriaForaFranquia(nba->listafranquias[j]);
				} else if(!strcmp(GetTime1Partida(nba->listapartidas[i]), GetNomeFranquia(nba->listafranquias[j]))) {
					AdicionaDerrotaCasaFranquia(nba->listafranquias[j]);
				}
			}
		}
	}

	return nba;
}

/**
 * @brief Imprime o relatório final da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba) {
	int vitLeste = 0, derLeste = 0, vitOeste = 0, derOeste = 0;
	for(int i = 0; i < nba->qtdfranquias; i++) {
		if(!strcmp(GetConferenciaFranquia(nba->listafranquias[i]), "LESTE")) {
			vitLeste += (GetVitoriaCasaFranquia(nba->listafranquias[i]) + GetVitoriaForaFranquia(nba->listafranquias[i]));
			derLeste += (GetDerrotaCasaFranquia(nba->listafranquias[i]) + GetDerrotaForaFranquia(nba->listafranquias[i]));
		} else {
			vitOeste += (GetVitoriaCasaFranquia(nba->listafranquias[i]) + GetVitoriaForaFranquia(nba->listafranquias[i]));
			derOeste += (GetDerrotaCasaFranquia(nba->listafranquias[i]) + GetDerrotaForaFranquia(nba->listafranquias[i]));
		}
	}

	for(int i = 0; i < nba->qtdfranquias; i++) {
		ImprimeFranquia(nba->listafranquias[i]);
	}

	if((vitLeste + derLeste)) 
		printf("LESTE %d %d %.2f\n", vitLeste, derLeste, 100.0*(vitLeste/(float) (vitLeste + derLeste)));
	else 
		printf("LESTE %d %d 0.00\n", vitLeste, derLeste);
	if((vitOeste + derOeste))
		printf("OESTE %d %d %.2f\n", vitOeste, derOeste, 100.0*(vitOeste/(float) (vitOeste + derOeste)));
	else 
		printf("OESTE %d %d 0.00\n", vitOeste, derOeste);
}

/**
 * @brief Libera a memória alocada para a instância da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba) {
	for(int i = 0; i < nba->qtdfranquias; i++) {
		LiberaFranquia(nba->listafranquias[i]);
	}

	free(nba->listafranquias);
	for(int i = 0; i < nba->qtdpartidas; i++) {
		LiberaPartida(nba->listapartidas[i]);
	}

	free(nba->listapartidas);
	
	free(nba);
}