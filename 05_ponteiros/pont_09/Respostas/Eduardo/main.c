#include <stdio.h>
#include "pessoa.h"

int main() {
    int N;
    scanf("%d\n", &N);
    tPessoa pessoas[N];

    for(int i = 0; i < N; i++) {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(&pessoas);
    
    for(int i = 0; i < N; i++) {
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}