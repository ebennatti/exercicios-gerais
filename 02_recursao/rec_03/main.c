#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

void leVetor(int numElementos, int vet[numElementos]);

int main() {
    int N = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int x = 0, qtd = 0;
        scanf("%d %d", &x, &qtd);
        int vet[qtd];
        leVetor(qtd, vet);
        printf("%d\n", ContaOcorrencias(vet, qtd, x));
    }
    
    return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
    /*
    Funcionamento da recursao:
        *decrementa numElementos, quando == 0, nao ha elementos a serem analisados
        *analisa vet[0] e compara com o numero procuraddo, se for igual, retorna 1 + a chamada da funcao
        *passa como parametro vet + 1, apontando o ponteiro para a proxima posicao, e decrementa numElementos
        *cada chamada cria um quadro na pilha (stack frame)
        *a ultima chamada e a primeira a finalizar, assim sucessivamente, somando os resultados
    */
    if(!numElementos)
        return 0;
    else {
        if(vet[0] == numeroProcurado)
            return 1 + ContaOcorrencias(vet + 1, numElementos - 1, numeroProcurado);
        else
            return ContaOcorrencias(vet + 1, numElementos - 1, numeroProcurado);
    }
}

void leVetor(int numElementos, int vet[numElementos]) {
    for(int i = 0; i < numElementos; i++) {
        scanf("%d", &vet[i]);
    }
    return;
}