#include <stdio.h>

int fibonacci(int n);

int main() {
    int N = 0;
    scanf("%d", &N);
    printf("%d\n", fibonacci(N));

    return 0;
}

int fibonacci(int n) {
    /*
    Funcionamento recursao:
        *verifica n == 1 e n == 0
        *comeca de tras para frente
        *adiciona os quadros na stack
        *a primeira chamada e a ultima a ser resolucionada
    */
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}