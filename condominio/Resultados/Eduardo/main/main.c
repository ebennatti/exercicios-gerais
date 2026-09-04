#include <stdio.h>
#include <string.h>
#include "data.h"
#include "morador.h"
#include "area.h"
#include "reserva.h"

#define MAX_RESERVAS 100

int main() {
    //areas do condominio
    int qtdAreas = 0;
    scanf("%d\n", &qtdAreas);
    Area areas[qtdAreas];
    for(int i = 0; i < qtdAreas; i++) {
        areas[i] = lerArea();
    }

    //moradores registrados
    int qtdMoradores = 0;
    scanf("%d\n", &qtdMoradores);
    Morador moradores[qtdMoradores];
    for(int i = 0; i < qtdMoradores; i++) {
        moradores[i] = lerMorador();
    }

    //reservas solicitadas
    int resSol = 0;
    scanf("%d\n", &resSol);
    Reserva reservas[resSol];

    //agenda de reservas
    Reserva agendaReservas[MAX_RESERVAS];
    int nRes = 0;

    for(int i = 0; i < resSol; i++) {
        //le e atribui reserva
        char idArea[MAX_TAM_ID];
        char cpf[MAX_TAM_CPF];
        Data dataRes;
        int qtdConvidados;
        scanf("%[^\n]\n", idArea);
        scanf("%[^\n]\n", cpf);
        dataRes = lerData();
        scanf("%d\n", &qtdConvidados);

        //reserva é valida?
        int achou = -1;
        for(int j = 0; j < qtdMoradores; j++) {
            if(verificaCPFMorador(moradores[j], cpf)) {
                achou = j;
            }
        }

        //procura area
        int a = -1;
        for(int j = 0; j < qtdAreas; j++) {
            if(verificaIdArea(areas[j], idArea))
                a = j;
        }
        if(achou >= 0) {
            if(verificaSolicitacaoReserva(agendaReservas, nRes, moradores[achou], areas[a], dataRes, qtdConvidados)) {
                agendaReservas[nRes] = criaReserva(moradores[achou], areas[a], dataRes, qtdConvidados);
                imprimeReserva(agendaReservas[nRes]);
                nRes++;
            }
            
        }
    }

    return 0;    
}