

#ifndef _ENCAMINHAMENTO_H
#define _ENCAMINHAMENTO_H


typedef struct _Encaminhamento Encaminhamento;

Encaminhamento *criaEncaminhamento(char *especialidade, char *nomePaciente, char *nomeMedico, char *motivo);


Encaminhamento *leEncaminhamento();


float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere);


void imprimeEncaminhamento(void *dado);


void desalocaEncaminhamento(void *dado);

#endif