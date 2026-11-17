#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "receita.h"

/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
struct _Receita {
    char nomeMedicamento[100], nomePaciente[100], nomeMedico[100], instrucoes[200];
};

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes) {
    Receita *r = (Receita *) calloc(1, sizeof(Receita));
    strcpy(r->instrucoes, instrucoes);
    strcpy(r->nomeMedicamento, nomeMedicamento);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->nomePaciente, nomePaciente);

    return r;

}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Receita *leReceita() {
//     DR. MUNDO  (nome do médico) 
// JOAO MATIAS (nome do paciente) 
// PARACETAMOL 500MG (nome do medicamento) 
// TOMAR EM CASO DE DOR (instruções para uso do medicamento)
    char nomeMedicamento[100], nomePaciente[100], nomeMedico[100], instrucoes[200];
    scanf("%[^\n]\n", nomeMedico);
    scanf("%[^\n]\n", nomePaciente);
    scanf("%[^\n]\n", nomeMedicamento);
    scanf("%[^\n]\n", instrucoes);

    return criaReceita(nomeMedicamento, nomePaciente, nomeMedico, instrucoes);

}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoReceita(void *dado, float precoCaractere) {
    Receita *r = (Receita *)dado;
    int tam = strlen(r->instrucoes) + strlen(r->nomeMedicamento) + strlen(r->nomeMedico) + strlen(r->nomePaciente);

    return tam * precoCaractere;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeReceita(void *dado) {
    Receita *r = (Receita *)dado;
    printf("- - RECEITA - -\n"); 
    printf("MEDICAMENTO: %s\n", r->nomeMedicamento); 
    printf("PACIENTE: %s\n", r->nomePaciente); 
    printf("INSTRUCOES: %s\n", r->instrucoes); 
    printf("MEDICO: %s\n", r->nomeMedico); 
    printf("- - - - - - - -\n");
}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaReceita(void *dado) {
    Receita *r = (Receita *)dado;
    free(r);
}