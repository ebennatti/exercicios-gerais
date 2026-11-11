#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exame.h"

/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
struct _Exame {
    char nomePaciente[101], nomeMedico[101], descricao[101];
};


Exame *criaExame(char *descricao, char *nomePaciente, char *nomeMedico) {
    Exame *e = (Exame *) calloc(1, sizeof(Exame));
    strcpy(e->descricao, descricao);
    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->nomePaciente, nomePaciente);

    return e;
}


Exame *leExame() {
    char nomePaciente[101], nomeMedico[101], descricao[101];
    scanf("%[^\n]\n", nomeMedico);
    scanf("%[^\n]\n", nomePaciente);
    scanf("%[^\n]\n", descricao);

    return criaExame(descricao, nomePaciente, nomeMedico);
}


float calculaPrecoImpressaoExame(void *dado, float precoCaractere) {
    Exame *e = (Exame *) dado;
    int tam = strlen(e->descricao) + strlen(e->nomeMedico) + strlen(e->nomePaciente);
    return tam*precoCaractere;
}


void imprimeExame(void *dado) {
    Exame *e = (Exame *) dado;
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", e->nomePaciente);
    printf("SOLICITACAO: %s\n", e->descricao);
    printf("MEDICO: %s\n", e->nomeMedico);
    printf("- - - - - - -\n");
}


void desalocaExame(void *dado) {
    Exame *e = (Exame *) dado;
    free(e);
}