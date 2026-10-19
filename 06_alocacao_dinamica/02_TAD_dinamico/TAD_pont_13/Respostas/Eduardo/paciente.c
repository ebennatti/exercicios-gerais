
// #define MAX_NOME_PAC 101
// #define MAX_CARTAO_SUS 19
// #define MAX_LESOES 10

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data.h"
#include "lesao.h"
#include "paciente.h"

// typedef struct {
//     char nome[MAX_NOME_PAC];    
//     char cartaoSus[MAX_CARTAO_SUS];
//     char genero;
//     Data *dataNasc;   
//     Lesao *lesoes[MAX_LESOES]; 
//     int numLesoes;
// } Paciente;

/*
Função que cria um paciente a partir dos parâmetros fornecidos.
@param nome: Nome do paciente.
@param cartaoSus: Cartão SUS do paciente.
@param genero: Gênero do paciente.
@param dataNasc: Data de nascimento do paciente.
@return Ponteiro para o paciente criado.
*/
Paciente *criaPaciente(char *nome, char *cartaoSus, char genero, Data *dataNasc) {
    Paciente *p = calloc(1, sizeof(Paciente));
    strcpy(p->cartaoSus, cartaoSus);
    strcpy(p->nome, nome);
    p->genero = genero;
    p->dataNasc = dataNasc;

    return p;
}

/*
Função que lê os dados de um paciente a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para o paciente lido.
*/
Paciente *lerPaciente() {
    //     NOME (nome do paciente) 
    // 19/11/1974 (data de nascimento do paciente) 
    // 123-1234-1234-1234 (cartão do SUS do paciente) 
    // O (gênero do paciente)
    char nome[MAX_NOME_PAC], cartaoSus[MAX_CARTAO_SUS], genero;
    Data *d;
    scanf("%[^\n]\n", nome);
    d = lerData();
    scanf("%[^\n]\n", cartaoSus);
    scanf("%c\n", &genero);

    return criaPaciente(nome, cartaoSus, genero, d);
}

/*
Função que vincula uma lesão a um paciente.
Basicamente, a lesão é adicionada à lista de lesões do paciente se houver espaço disponível.
O vínculo é realizado de acordo com o cartão do SUS.
@param p: Ponteiro para o paciente ao qual a lesão será vinculada.
@param l: Ponteiro para a lesão a ser vinculada ao paciente.
*/
void vinculaLesaoPaciente(Paciente *p, Lesao *l) {
    if(p->numLesoes < MAX_LESOES) {
        p->lesoes[p->numLesoes] = l;
        p->numLesoes++;
    }
}

/*
Função que calcula a idade do paciente em anos completos com base em uma data de referência.
@param p: O paciente cuja idade será calculada.
@param dataBase: A data de referência para o cálculo da idade.
@return A idade do paciente em anos completos.
*/
int calculaIdadePaciente(Paciente *p, Data *dataBase) {
    return diferencaAnoData(p->dataNasc, dataBase);
}

/*
Função que obtém o cartão SUS de um paciente.
@param p: Ponteiro para o paciente do qual se deseja obter o cartão SUS.
@return Ponteiro para cartão SUS do paciente.
*/
char *getCartaoSusPaciente(Paciente *p) {
    return p->cartaoSus;
}

/*
Função que obtém o número de lesões associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões será obtida.
@return O número de lesões do paciente.
*/
int getNumLesoesPaciente(Paciente *p) {
    return p->numLesoes;
}

/*
Função que calcula a quantidade de lesões cirúrgicas (malignas) associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões cirúrgicas será calculada.
@return A quantidade de lesões cirúrgicas do paciente.
*/
int qtdLesoesCirurgicasPaciente(Paciente *p) {
    int qtdLesoes = 0;
    for(int i = 0; i < p->numLesoes; i++) {
        if(verificaCirurgicaLesao(p->lesoes[i]))
            qtdLesoes++;
    }

    return qtdLesoes;
}

/*
Função que imprime o nome do paciente e o ID das lesões associadas a ele (exatamente como solicitado no enunciado e nos casos de teste).
@param p: Ponteiro para o paciente cujas informações serão impressas.
*/
void imprimePaciente(Paciente *p) {
    //- SON GOKU - L1 L3
    if(p->numLesoes) {
        printf("- %s - ", p->nome);
        for(int i = 0; i < p->numLesoes; i++) {
            imprimeIdLesao(p->lesoes[i]);
            printf(" ");
        }
        printf("\n");
    }
}

/*
Função que libera a memória alocada para um paciente.
@param p: Ponteiro para o paciente a ser liberado.
*/
void liberaPaciente(Paciente *p) {
    for(int i = 0; i < p->numLesoes; i++)
        free(p->lesoes[i]);
    liberaData(p->dataNasc);
    free(p);
}