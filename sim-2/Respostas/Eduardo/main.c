#include <stdio.h>
#include "estacionamento.h"
#include "veiculo.h"
#include "datahora.h"

int main() {
    char c;
    Estacionamento *e = criaEstacionamento();
    while(scanf("%c\n", &c) == 1 && c != 'F') {
        if(c == 'E') {
            registraEntradaEstacionamento(e, lerVeiculo());
        } else if(c == 'S') {
            char placa[MAX_PLACA_VEIC];
            scanf("%[^\n]\n", placa);
            DataHora *saida = lerDataHora();
            if(!registraSaidaEstacionamento(e, placa, saida)) {
                liberaDataHora(saida);
            }
        }
    }
    printf("TOTAL ENTRADAS: %d\n", getTotalEntradasEstacionamento(e));
    printf("TOTAL SAIDAS: %d\n", getTotalSaidasEstacionamento(e));
    if(getTotalSaidasEstacionamento(e))
        printf("PERMANENCIA MEDIA (MIN): %d\n", calculaPermanenciaTotalEstacionamento(e)/getTotalSaidasEstacionamento(e));
    else 
        printf("PERMANENCIA MEDIA (MIN): -\n");
    printf("FATURAMENTO (R$): %d\n", calculaFaturamentoEstacionamento(e));
    printf("VEICULOS NO PATIO: %d\n", getTotalNoPatioEstacionamento(e));
    printf("LISTA DE VEICULOS NO PATIO:\n");
    imprimeVeiculosNoPatioEstacionamento(e);


    liberaEstacionamento(e);
}