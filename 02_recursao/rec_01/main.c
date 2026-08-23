#include <stdio.h>

#define MAX_CHAR 1000

void ImprimeInvertido(char string[]);

int contaVetor(char string[]);

int leVetor(char string[]);

void imprimeVet(char string[]);

int main() {
    char string[MAX_CHAR];
    int qtd = 0;
    while(scanf("%s", string) == 1) {
        ImprimeInvertido(string);
        printf(" ");
    }
    return 0;
}

void ImprimeInvertido(char string[]) {
    if(string[0] == '\0')
        return;
    else {
        ImprimeInvertido(string + 1);
        printf("%c", string[0]);
    }
    return;
}