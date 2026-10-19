#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paciente.h"
#include "lesao.h"
#include "data.h"

#define MAX_PAC 100

int main() {
    Paciente **listaPacientes = NULL;
    Lesao **lesoes = NULL;
    Data *dataBase = criaData(12, 9, 2023);
    char op;
    int numPac = 0, numLesoes = 0, somaIdades = 0;

    while(scanf("%c\n", &op) == 1) {
        if(op == 'P') {
            if(numPac < MAX_PAC) {
                numPac++;
                listaPacientes = realloc(listaPacientes, (numPac)*sizeof(Paciente*));
                listaPacientes[numPac - 1] = lerPaciente();
                somaIdades += calculaIdadePaciente(listaPacientes[numPac - 1], dataBase);
            }
        } else if(op == 'L') {
            numLesoes++;
            lesoes = realloc(lesoes, numLesoes*sizeof(Lesao*));
            lesoes[numLesoes - 1] = lerLesao();
        } else if(op == 'F') {
            break;
        }
    }

    for(int i = 0; i < numLesoes; i++) {
        for(int j = 0; j < numPac; j++) 
            if(!strcmp(getCartaoSusLesao(lesoes[i]), getCartaoSusPaciente(listaPacientes[j]))) {
                vinculaLesaoPaciente(listaPacientes[j], lesoes[i]);
                lesoes[i] = NULL;
                break;
            }
    }

    //     TOTAL PACIENTES: 4
    // MEDIA IDADE (ANOS): 29
    // TOTAL LESOES: 3
    // TOTAL CIRURGIAS: 2
    // LISTA DE PACIENTES:
    // - TRISTANA - L8  
    // - LUCIAN - L2  
    // - LUX - L100  

    printf("TOTAL PACIENTES: %d\n", numPac);
    if(somaIdades)
        printf("MEDIA IDADE (ANOS): %d\n", somaIdades/numPac);
    else 
        printf("MEDIA IDADE (ANOS): -\n");
    printf("TOTAL LESOES: ");
    int qtdLesoes = 0;
    for(int i = 0; i < numPac; i++) {
        qtdLesoes += getNumLesoesPaciente(listaPacientes[i]);
    }
    printf("%d\n", qtdLesoes);

    if(numLesoes) {
        printf("TOTAL CIRURGIAS: ");

        int qtdCirurgias = 0;
        for(int i = 0; i < numPac; i++) {
            qtdCirurgias += qtdLesoesCirurgicasPaciente(listaPacientes[i]);
        }
        printf("%d\n", qtdCirurgias);
    } else {
        printf("TOTAL CIRURGIAS: 0\n");
    }



    printf("LISTA DE PACIENTES:\n");
    if(numPac) {
        for(int i = 0; i < numPac; i++) {
            imprimePaciente(listaPacientes[i]);
        }
    }

    for(int i = 0; i < numPac; i++) {
        liberaPaciente(listaPacientes[i]);
    }
    free(listaPacientes);

    for(int i = 0; i < numLesoes; i++) {
        if(lesoes[i] != NULL)
            liberaLesao(lesoes[i]);
    }
    free(lesoes);

    liberaData(dataBase);
    return 0;
}