#include <stdio.h>

#include "agencia.h"
#include "conta.h"
#include "operacao.h"

int main() {
    printf("--- Agencia Bancaria ---\n");
    tAgencia *a = CriaAgencia();
    LeOperacoes(a);
    ImprimeOperacoesSuspeitas(a);
    ImprimeDoisCorrentistasComMaiorSaldo(a);
    ImprimeSaldoTotal(a);
    DestroiAgencia(a);
    return 0;
}