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
    /*
    Funcionamento da recursao:
        *caso o primeiro caractere seja nulo (\0), retorna
        *se nao for, chama a funcao novamente chamando como parametro string + 1,
        fazendo o ponteiro apontar para o proximo char
        *a primeira chamada fica na stack e so e executada apos todas as outras, assim sucessivamente
        *a string e impressa invertida
    */
    if(string[0] == '\0')
        return;
    else {
        ImprimeInvertido(string + 1);
        printf("%c", string[0]);
    }
    return;
}