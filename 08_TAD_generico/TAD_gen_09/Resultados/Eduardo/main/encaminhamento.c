#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encaminhamento.h"

struct _Encaminhamento {
    char nomeMedico[101], nomePaciente[101], especialidade[101], motivo[101];
};

Encaminhamento *criaEncaminhamento(char *especialidade, char *nomePaciente, char *nomeMedico, char *motivo) {
    Encaminhamento *c = (Encaminhamento *) calloc(1, sizeof(Encaminhamento));
    strcpy(c->especialidade, especialidade);
    strcpy(c->motivo, motivo);
    strcpy(c->nomeMedico, nomeMedico);
    strcpy(c->nomePaciente, nomePaciente);

    return c;
}


Encaminhamento *leEncaminhamento() {
    char nomeMedico[101], nomePaciente[101], especialidade[101], motivo[101];
    scanf("%[^\n]\n", nomeMedico);
    scanf("%[^\n]\n", nomePaciente);
    scanf("%[^\n]\n", especialidade);
    scanf("%[^\n]\n", motivo);

    return criaEncaminhamento(especialidade, nomePaciente, nomeMedico, motivo);
}


float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere) {
    Encaminhamento *c = (Encaminhamento *) dado;
    int tam = strlen(c->especialidade) + strlen(c->motivo) + strlen(c->nomeMedico) + strlen(c->nomePaciente);

    return tam * precoCaractere;
}


void imprimeEncaminhamento(void *dado) {
    Encaminhamento *c = (Encaminhamento *) dado;

    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", c->nomePaciente);
    printf("ESPECIALIDADE: %s\n", c->especialidade);
    printf("MOTIVO: %s\n", c->motivo);
    printf("MEDICO: %s\n", c->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}


void desalocaEncaminhamento(void *dado) {
    Encaminhamento *c = (Encaminhamento *) dado;
    free(c);
}