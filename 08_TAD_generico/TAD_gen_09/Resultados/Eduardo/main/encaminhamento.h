

#ifndef _ENCAMINHAMENTO_H
#define _ENCAMINHAMENTO_H


typedef struct _Encaminhamento Encaminhamento;


Encaminhamento *criaEncaminhamento(char *motivo, char *nomePaciente, char *nomeMedico, char *especialidade);

Encaminhamento *leEncaminhamento();

float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere);

void imprimeEncaminhamento(void *dado);

void desalocaEncaminhamento(void *dado);

#endif