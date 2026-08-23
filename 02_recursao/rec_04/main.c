#include <stdio.h>

#define MAX_CHAR 1000

int palindromo(char *string, int tamanho);

int tamanhoString(char *string);

int main() {

    char string[MAX_CHAR];
    while(scanf("%s", string) == 1) {
        if(palindromo(string, tamanhoString(string)))
            printf("SIM\n");
        else 
            printf("NAO\n");
    }

    return 0;
}

int palindromo(char *string, int tamanho) {
    /*
    Funcionamento recursao:
        *verifica parada: == 1 para string impar e == 0 para string par
        *compara primeiro e ultimo char, retorna 0 se forem diferentes
        *passa como parametro string + 1, apontando o ponteiro para prox char
        *passa tamanho - 2, para analisar o prox ultimo elemento
        *adiciona quadro na stack, o retorno da ultima funcao a ser chamada 
        sera o retorno da primeira
    */
    if(tamanho <= 1)
        return 1;
    else {
        if(string[0] == string[tamanho - 1])
            return palindromo(string + 1, tamanho - 2);
        else   
            return 0;
    }
}

int tamanhoString(char *string) {
    int i = 0;
    for(i = 0; string[i] != '\0'; i++);

    return i;
}