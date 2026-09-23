#include <stdio.h>
#include "livro.h"
#include "biblioteca.h"

void imprimeMenu() {
    printf("Lista de operacoes:\n"
    "1 - Cadastrar livros.\n"
    "2 - Remover livros.\n"
    "3 - Listar todos os livros cadastrados.\n\n");
}

int main() {
    int N;
    scanf("%d\n", &N);
    tBiblioteca b;
    b = inicializarBiblioteca();

    imprimeMenu();
    for(int i = 0; i < N; i++) {
        tLivros l;
        int opcao = 0;
        scanf("%d\n", &opcao);

        if(opcao == 1) {
            l = lerLivro();
            b = adicionarLivroNaBiblioteca(b, l);
        } else if(opcao == 2) {
            char titulo[100];
            scanf("%[^\n]\n", titulo);
            b = removerLivroDaBiblioteca(b, titulo);
        } else if(opcao == 3) {
            listarLivrosDaBiblioteca(b);
        } else {
            printf("Operacao invalida!\n");
            return 0;
        }
    }

    return 0;
}