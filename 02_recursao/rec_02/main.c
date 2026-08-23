#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos); 

void leVetor(int numElementos ,int vet[numElementos]);

int main() {
    int N = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        int numElementos = 0;
        scanf("%d", &numElementos);

        int vetor[numElementos];
        leVetor(numElementos, vetor);
        printf("%d", SomaElementosPares(vetor, numElementos));
        printf("\n");
    }
    return 0;
}

int SomaElementosPares(int* vet, int numElementos) {
    /*
    Funcionamento da recursao:
        *verifica se numElementos > 0, para nao ocorrer acesso fora dos limites
        *soma vet[numElementos - 1] + chamada de funcao, e decrementa numElementos,
        percorrendo o vetor de tras para frente
        *verifica se e par ou impar, caso par, soma o numero com a chamada, caso impar,
        somente chama a funcao
    */
    if(!numElementos)
        return 0;
    else if(vet[numElementos - 1] % 2 == 0)
        return vet[numElementos - 1] + SomaElementosPares(vet, numElementos - 1);
    else
        return SomaElementosPares(vet, numElementos - 1);
}

void leVetor(int numElementos ,int vet[numElementos]) {
    for(int i = 0; i < numElementos; i++) {
        scanf("%d", &vet[i]);
    }
}
