
/*
//Estrutura para representar um evento no calendário. 
typedef struct {
    char nome[50]; // Nome do evento.
    int dia;       // Dia do evento.
    int mes;       // Mês do evento.
    int ano;       // Ano do evento.
} Evento;
*/

#include <stdio.h>
#include <string.h>
#include "evento.h"

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos) {
    scanf(" %[^\n]", eventos[*numEventos].nome);
    scanf(" %d %d %d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano); 
    *numEventos += 1;
    printf("Evento cadastrado com sucesso!\n");
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos) {

    printf("Eventos cadastrados:\n");

    for(int i = 0; i < *numEventos; i++) {
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);    
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos) {
    int evento;
    scanf(" %d", &evento);
    if(evento < 0 || evento >= *numEventos) {
        printf("Indice invalido!\n");
    } else {
        scanf(" %d %d %d", &eventos[evento].dia, &eventos[evento].mes, &eventos[evento].ano);
        printf("Data modificada com sucesso!\n");
    }
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos) {
    Evento temp;
    if(*indiceA < 0 || *indiceA >= *numEventos || *indiceB < 0 || *indiceB >= *numEventos) {
        printf("Indices invalidos!\n");
    } else {
        temp = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = temp;
        printf("Eventos trocados com sucesso!\n");
    }
}
