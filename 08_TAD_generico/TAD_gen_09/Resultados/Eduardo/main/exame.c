#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "exame.h"

struct _Exame {
    char descricao[100], nomePaciente[100], nomeMedico[100];
};


Exame *criaExame(char *descricao, char *nomePaciente, char *nomeMedico) {
    Exame *e = (Exame *) calloc(1, sizeof(Exame));
    strcpy(e->descricao, descricao);
    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->nomePaciente, nomePaciente);

    return e;

}

Exame *leExame() {
//     DR. MUNDO (nome do médico) 
// JAYCE BARBOSA (nome do paciente) 
// RESSONANCIA MAGNETICA PARA AVALIACAO DA LOMBAR (justificativa) 
    char descricao[100], nomePaciente[100], nomeMedico[100];
    scanf("%[^\n]\n", nomeMedico);
    scanf("%[^\n]\n", nomePaciente);
    scanf("%[^\n]\n", descricao);

    return criaExame(descricao, nomePaciente, nomeMedico);
}

float calculaPrecoImpressaoExame(void *dado, float precoCaractere) {
    Exame *e = (Exame *)dado;
    int tam = strlen(e->descricao) + strlen(e->nomeMedico) + strlen(e->nomePaciente);

    return tam * precoCaractere;
}

void imprimeExame(void *dado) {
    Exame *e = (Exame *)dado;
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", e->nomePaciente);
    printf("SOLICITACAO: %s\n", e->descricao); 
    printf("MEDICO: %s\n", e->nomeMedico);
    printf("- - - - - - -\n");
}

void desalocaExame(void *dado) {
    Exame *e = (Exame *)dado;
    free(e);
}