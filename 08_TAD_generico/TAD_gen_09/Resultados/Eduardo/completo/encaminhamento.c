#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encaminhamento.h"

struct _Encaminhamento {
    char motivo[200], nomePaciente[100], nomeMedico[100], especialidade[50];
};


Encaminhamento *criaEncaminhamento(char *motivo, char *nomePaciente, char *nomeMedico, char *especialidade) {
    Encaminhamento *e = (Encaminhamento *) calloc(1, sizeof(Encaminhamento));
    strcpy(e->motivo, motivo);
    strcpy(e->nomePaciente, nomePaciente);
    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->especialidade, especialidade);

    return e;

}

Encaminhamento *leEncaminhamento() {
//     DR. JOSE CARDOSO (nome do médico) 
// ALDIN FERREIRA (nome do paciente) 
// CARDIOLOGIA (especialidade a ser encaminhado) 
// ANALISAR POSSIVEL INFARTO (justificativa para o encaminhamento) 

    char motivo[200], nomePaciente[100], nomeMedico[100], especialidade[50];
    scanf("%[^\n]\n", nomeMedico);
    scanf("%[^\n]\n", nomePaciente);
    scanf("%[^\n]\n", especialidade);
    scanf("%[^\n]\n", motivo);

    return criaEncaminhamento(motivo, nomePaciente, nomeMedico, especialidade);
    
}

float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere) {
    Encaminhamento*e = (Encaminhamento *)dado;
    int tam = strlen(e->especialidade ) + strlen(e->motivo) + strlen(e->nomeMedico) + strlen(e->nomePaciente);

    return tam * precoCaractere;
}

void imprimeEncaminhamento(void *dado) {
    Encaminhamento*e = (Encaminhamento *)dado;
    printf("- - ENCAMINHAMENTO - -\n"); 
    printf("PACIENTE: %s\n", e->nomePaciente);
    printf("ESPECIALIDADE: %s\n", e->especialidade); 
    printf("MOTIVO: %s\n", e->motivo); 
    printf("MEDICO: %s\n", e->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}

void desalocaEncaminhamento(void *dado) {
    Encaminhamento*e = (Encaminhamento *)dado;
    free(e);
}