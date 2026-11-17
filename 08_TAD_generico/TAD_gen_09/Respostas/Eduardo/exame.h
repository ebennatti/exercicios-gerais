

#ifndef _EXAME_H
#define _EXAME_H


typedef struct _Exame Exame;


Exame *criaExame(char *descricao, char *nomePaciente, char *nomeMedico);

Exame *leExame();

float calculaPrecoImpressaoExame(void *dado, float precoCaractere);

void imprimeExame(void *dado);

void desalocaExame(void *dado);

#endif