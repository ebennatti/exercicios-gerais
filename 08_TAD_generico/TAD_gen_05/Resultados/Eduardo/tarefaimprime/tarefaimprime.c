#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefaimprime.h"

struct impr {
    char str[100];
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg) {
    tImpr *m = (tImpr *) calloc(1, sizeof(tImpr));
    strcpy(m->str, msg);
    return m;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp) {
    tImpr *m = (tImpr *)imp;
    printf("\n%s", m->str);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp) {
    tImpr *m = (tImpr *)imp;
    free(m);
}