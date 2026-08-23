#include <stdio.h>

int somaDigitos(int n); 

int main() {
    int N = 0;
    scanf("%d", &N);

    printf("%d\n", somaDigitos(N));
    return 0;
}

int somaDigitos(int n) {
    /* 
    Recursivo: soma o último dígito (n % 10) com a soma dos dígitos
        do restante do número (n / 10, que descarta esse último dígito),
        até n chegar a 0, quando não sobra mais dígito e a função retorna 0. 
    */
    if(n <= 0)
        return 0;
    else {
        return (n % 10) + somaDigitos(n/10);
    }
}