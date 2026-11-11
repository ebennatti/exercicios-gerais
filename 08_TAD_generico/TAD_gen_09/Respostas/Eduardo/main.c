#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encaminhamento.h"
#include "exame.h"
#include "receita.h"
#include "documento.h"
#include "fila_imp.h"

int main () {
    float precoCaracter;
    char opcao[101];
    FilaImp *f = criaFilaImp();
    scanf("%f\n", &precoCaracter);
    while(scanf("%[^\n]\n", opcao) == 1 && strcmp(opcao, "FIM") != 0) {
        if(!strcmp(opcao, "RECEITA")) {
            Receita *r = leReceita();
            insereDocumentoFilaImp(f, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        } else if(!strcmp(opcao, "ENCAMINHAMENTO")) {
            Encaminhamento *e = leEncaminhamento();
            insereDocumentoFilaImp(f, e, imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);
        } else if(!strcmp(opcao, "EXAME")) {
            Exame *ex = leExame();
            insereDocumentoFilaImp(f, ex, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        } else if(!strcmp(opcao, "IMPRIME")) {
            if(quantidadeDocumentosNaFilaImp(f)) {
                imprimeFilaImp(f);
            }
        } else if(!strcmp(opcao, "PRECO")) {
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(f, precoCaracter));
        } else if(!strcmp(opcao, "QUANTIDADE")) {
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(f));
        } 

    }

    desalocaFilaImp(f);

    return 0;
}