#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estacao.h"
#include "utils.h"
#include "veiculo.h"
#include "carregador.h"

int main () {
    char c;
    int qtdEsts = 0, qtdVeis = 0, qtdCars = 0, qtdRecargas = 0;
    Estacao **ests = NULL;
    Veiculo **veis = NULL;

    while(scanf("%c\n", &c) == 1 && c != 'F') {
        if(c == 'E') {
            ests = (Estacao **) realloc(ests, (qtdEsts + 1)*sizeof(Estacao *));
            ests[qtdEsts] = lerEstacao();
            qtdEsts++;
        } else if(c == 'C') {
            Carregador *c = lerCarregador();
            insereCarregadorEstacoes(ests, qtdEsts, c);
        } else if(c == 'V') {
            veis = (Veiculo **) realloc(veis, (qtdVeis + 1)*sizeof(Veiculo *));
            veis[qtdVeis] = lerVeiculo();
            qtdVeis++;
        } else if(c == 'R') {
            realizaRecarga(ests, qtdEsts, veis, qtdVeis);
        }
    }

    char relat[20];
    scanf("%s", relat);

    printf("TOTAL ESTACOES: %d\n", qtdEsts);

    for(int i = 0; i < qtdEsts; i++)
        qtdCars += obtemNumCarregadoresEstacao(ests[i]);
    printf("TOTAL CARREGADORES: %d\n", qtdCars);

    for(int i = 0; i < qtdEsts; i++)
        qtdRecargas += qtdRecargasEstacao(ests[i]);
    printf("TOTAL RECARGAS: %d\n", qtdRecargas);

    int recComp = 0;
    for(int i = 0; i < qtdEsts; i++)
        recComp += qtdRecargasCompletasEstacao(ests[i]); 
    printf("RECARGAS COMPLETAS: %d\n", recComp);

    int entregue = 0;
    for(int i = 0; i < qtdEsts; i++)
        entregue += calculaEnergiaEstacao(ests[i]);
    printf("ENERGIA TOTAL (KWH): %d\n", entregue);

    int fatTotal = 0;
    for(int i = 0; i < qtdEsts; i++)
        fatTotal += calculaFaturamentoEstacao(ests[i]);
    printf("FATURAMENTO TOTAL (R$): %d\n", fatTotal);

    if(!strcmp(relat, "COMPLETO")) {
        printf("LISTA DE FATURAMENTO:\n");
        for(int i = 0; i < qtdEsts; i++)
            imprimeFaturamentoEstacao(ests[i]);
    }

    for(int i = 0; i < qtdEsts; i++) 
        liberaEstacao(ests[i]);
    free(ests);

    for(int i = 0; i < qtdVeis; i++)
        liberaVeiculo(veis[i]);
    free(veis);

    return 0;
}