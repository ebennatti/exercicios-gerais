#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "documento.h"
#include "fila_imp.h"

/*
    Estrutura do tipo FilaImp contendo os atributos necessários para a manipulação
*/
struct _FilaImp {
    Documento **listaDocs;
    int qtd;
};

/*
    Função que cria uma fila de impressão e retorna o seu endereço de memória
    @return: endereço de memória da fila de impressão criada
*/
FilaImp *criaFilaImp() {
    FilaImp *lista = (FilaImp *) calloc(1, sizeof(FilaImp));
    lista->listaDocs = NULL;
    lista->qtd = 0;

    return lista;
}

/*
    Função que desaloca uma fila de impressão
    @param f: ponteiro para a fila de impressão a ser desalocada
*/
void desalocaFilaImp(FilaImp *f) {
    for(int i = 0; i < f->qtd; i++) {
        desalocaDocumento(f->listaDocs[i]);
    }
    free(f->listaDocs);

    free(f);
}

/*
    Função que insere um documento na fila de impressão de acordo com a especificação
    @param f: ponteiro para a fila de impressão onde o documento será inserido
    @param dado: ponteiro genérico para o dado do documento a ser inserido
    @param imprime: ponteiro para a função de impressão do dado do documento genérico
    @param desaloca: ponteiro para a função de desalocação do dado do documento genérico
    @param calculaPreco: ponteiro para a função de cálculo do preço do dado do documento genérico
*/
void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprime imprime,
                            func_ptr_desaloca desaloca, func_ptr_calculaPreco calculaPreco) {
    f->listaDocs = (Documento **) realloc(f->listaDocs, (f->qtd + 1)*sizeof(Documento *));
    f->listaDocs[f->qtd] = criaDocumento(dado, imprime, desaloca, calculaPreco); 
    f->qtd++;
}
/*
    Função que retorna a quantidade de documentos na fila de impressão
    @param f: ponteiro para a fila de impressão
    @return: quantidade de documentos na fila de impressão
*/
int quantidadeDocumentosNaFilaImp(FilaImp *f) {
    return f->qtd;
}

/*
    Função que calcula o preço total de impressão de todos os documentos na fila de impressão
    @param f: ponteiro para a fila de impressão
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço total de impressão da fila
*/
float precoTotalImpressaoFilaImp(FilaImp *f, float precoCaractere) {
    float preco = 0;
    for(int i = 0; i < f->qtd; i++) {
        preco += calculaPrecoImpressaoDocumento(f->listaDocs[i], precoCaractere);
    }

    return preco;
}

/*
    Função que imprime toda a fila de impressão
    Obviamente, se não houver elementos na fila, a função não deve fazer nada.
    @param f: ponteiro para a fila de impressão
*/
void imprimeFilaImp(FilaImp *f) {
    for(int i = 0; i < f->qtd; i++) {
        imprimeDocumento(f->listaDocs[i]);
    }
}