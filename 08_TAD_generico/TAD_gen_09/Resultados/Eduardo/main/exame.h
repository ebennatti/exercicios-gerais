

#ifndef _EXAME_H
#define _EXAME_H

/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
typedef struct _Exame Exame;

Exame *criaExame(char *descricao, char *nomePaciente, char *nomeMedico);


Exame *leExame();


float calculaPrecoImpressaoExame(void *dado, float precoCaractere);


void imprimeExame(void *dado);


void desalocaExame(void *dado);

#endif