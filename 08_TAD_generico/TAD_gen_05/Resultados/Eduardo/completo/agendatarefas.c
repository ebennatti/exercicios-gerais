#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "agendatarefas.h"

typedef struct {
    int prioridade;
    void *tar;
    void (*executa)(void *);
    void (*libera)(void *);
} tTarefas;

struct agendatarefas {
    tTarefas *tarefas;
    int qtd, qtdAlocada;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas *a = (tAgendaTarefas *) calloc(1, sizeof(tAgendaTarefas));
    a->qtd = numElem;
    a->tarefas = (tTarefas *) calloc(a->qtd, sizeof(tTarefas));
    a->qtdAlocada = 0;
    return a;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    for(int i = 0; i < tar->qtd; i++) {
        tar->tarefas[i].libera(tar->tarefas[i].tar);
    }
    free(tar->tarefas);
    free(tar);
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ) {
    tar->tarefas[tar->qtdAlocada].tar = tarefa;
    tar->tarefas[tar->qtdAlocada].executa = executa;
    tar->tarefas[tar->qtdAlocada].libera = destroi;
    tar->tarefas[tar->qtdAlocada].prioridade = prioridade;
    tar->qtdAlocada++;
}   

int cmp_int(const void *a, const void *b) {
    tTarefas x = *(const tTarefas *)a;
    tTarefas y = *(const tTarefas *)b;

    return (x.prioridade < y.prioridade) - (x.prioridade > y.prioridade);
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {
    qsort(tar->tarefas, tar->qtd, sizeof(tTarefas), cmp_int);

    for(int i = 0; i < tar->qtd; i++) {
        tar->tarefas[i].executa(tar->tarefas[i].tar);
    }

}
