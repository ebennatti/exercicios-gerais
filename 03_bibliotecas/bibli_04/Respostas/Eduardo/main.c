#include <stdio.h>
#include "data.h"

int main() {
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if(verificaDataValida(dia, mes, ano)) {
        //imprime por extenso
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);

        //verifica se eh bissexto
        if(verificaBissexto(ano)) 
            printf("O ano informado eh bissexto\n");
        else
            printf("O ano informado nao eh bissexto\n");

        //informa qtd de dias do mes
        printf("O mes informado possui %02d dias\n", numeroDiasMes(mes, ano));

        //imprime data seguinte
        printf("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);
    } else 
        printf("A data informada eh invalida\n");

    return 0;
}