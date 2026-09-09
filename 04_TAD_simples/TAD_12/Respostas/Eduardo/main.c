#include <stdio.h>
#include <string.h>
#include "lesao.h"
#include "paciente.h"
#include "data.h"

#define MAX_NUM_PAC 100

int comparaCartaoSus(char *cartao1, char *cartao2) {
    if(strcmp(cartao1, cartao2) == 0)
        return 1;
    else    
        return 0;
}

int main() {
    Paciente p[MAX_NUM_PAC];
    char C;
    int i = 0, pacientes = 0, lesoes = 0, somaIdade = 0, qtdCirurgias = 0;
    //12/09/2023
    Data dBase = criaData(12, 9, 2023);
    while(scanf("%c\n", &C) == 1 && C != 'F') {
        Lesao l;
        if(C == 'P') {
            p[i] = lerPaciente();
            somaIdade += calculaIdadePaciente(p[i], dBase);
            pacientes++;
            i++;

        } else if(C == 'L') {
            l = lerLesao();
            for(int j = 0; j < i; j++) {
                char cartaoSusLesao[MAX_CARTAO_SUS], cartaoSusPaciente[MAX_CARTAO_SUS];
                getCartaoSusLesao(l, cartaoSusLesao);
                getCartaoSusPaciente(p[j], cartaoSusPaciente);
                if(comparaCartaoSus(cartaoSusLesao, cartaoSusPaciente)) {
                   p[j] = vinculaLesaoPaciente(p[j], l);
                   qtdCirurgias += verificaCirurgicaLesao(l);
                   lesoes++;
                }
            }
        }
    }

  
    printf("TOTAL PACIENTES: %d\n", pacientes);
    if(somaIdade)
        printf("MEDIA IDADE (ANOS): %d\n", somaIdade/pacientes);
    else
        printf("MEDIA IDADE (ANOS): -\n");
    printf("TOTAL LESOES: %d\n", lesoes);
    printf("TOTAL CIRURGIAS: %d\n", qtdCirurgias);
    printf("LISTA DE PACIENTES:\n");
    for(int i = 0; i < pacientes; i++) {
        imprimePaciente(p[i]);
    }
    return 0;
}