#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"

int main() {
    int N, i = 0;
    printf("Digite o numero de tarefas:");
    scanf("%d\n", &N);
    tAgendaTarefas *a = CriaAgendaDeTarefas(N);
    while(i < N) {
        int p;
        char op;
        scanf("%d %c ", &p, &op);
        if(op == 'I') {
            char msg[100];
            scanf("%[^\n]\n", msg);
            CadastraTarefaNaAgenda(a, p, CriaTarefaImprimir(msg), ExecutaTarefaImprimir, DestroiTarefaImprimir);
            i++;
        } else if(op == 'M') {
            float n1, n2;
            scanf("%f %f\n", &n1, &n2);
            CadastraTarefaNaAgenda(a, p, CriaTarefaMultiplicar(n1, n2), ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
            i++;
        } else if(op == 'S') {
            float n1, n2;
            scanf("%f %f\n", &n1, &n2);
            CadastraTarefaNaAgenda(a, p, CriaTarefaSoma(n1, n2), ExecutaTarefaSoma, DestroiTarefaSoma);
            i++;
        } else {
            char aux[100];
            scanf("%[^\n]\n", aux);
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
        }
    }   

    ExecutarTarefasDaAgenda(a);
    DestroiAgendaDeTarefas(a);
    return 0;
}