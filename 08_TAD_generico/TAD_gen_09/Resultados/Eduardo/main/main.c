#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exame.h"
#include "receita.h"
#include "encaminhamento.h"
#include "documento.h"
#include "fila_imp.h"


int main() {
    float custoChar;
    char op[20];
    FilaImp *f = criaFilaImp();
    scanf("%f\n", &custoChar);

    while(scanf("%[^\n]\n", op) == 1 && strcmp(op, "FIM") != 0) {
        if(!strcmp(op, "RECEITA")) {
           Receita *r = leReceita();
           insereDocumentoFilaImp(f, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        } else if(!strcmp(op, "ENCAMINHAMENTO")) {
            Encaminhamento *e = leEncaminhamento();
           insereDocumentoFilaImp(f, e, imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);
        } else if(!strcmp(op, "EXAME")) {
            Exame *ex = leExame();
           insereDocumentoFilaImp(f, ex, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        }else if(!strcmp(op, "QUANTIDADE")) {
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(f));    
        } else if(!strcmp(op, "PRECO")) {
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(f, custoChar));
        } else if(!strcmp(op, "IMPRIME")) {
            imprimeFilaImp(f);
        }
    }

    desalocaFilaImp(f);

    return 0;
}