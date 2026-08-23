#include <stdio.h>

int fatorial(int n);

int main() {
    int N = 0;
    scanf("%d", &N);
    
    printf("%d\n", fatorial(N));
    return 0;
}

int fatorial(int n) {
    /*
    Funcionamento recursao:
        *finaliza quando n == 1
        *adicona quadros na stack, resolvendo a ultima chamada primeiro
    */
    if(n == 1)
        return 1;
    else {
        return n*fatorial(n - 1);
    }
}