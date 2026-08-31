#include <stdio.h>
#include "string_utils.h"

#define MAX_CHAR 1000

void print_menu() {
    printf("1 - Tamanho da string\n"
    "2 - Copiar string\n"
    "3 - Converter string para letras maiusculas\n"
    "4 - Converter string para letras minusculas\n"
    "5 - Imprimir string ao contrario\n"
    "6 - Encerrar o programa\n"
    "Opcao escolhida: \n");
}

int main() {
    char str[MAX_CHAR];

    scanf("%[^\n]", str);

    //loop de operacoes
    int operacao = 0;
    print_menu();
    while(scanf("%d", &operacao) && operacao != 6) {
        if(operacao == 1) {
            printf("Tamanho da string: %d\n", string_length(str));
        } else if(operacao == 2) {
            char copy[MAX_CHAR];
            string_copy(str, copy);
            printf("String copiada: %s\n", copy);
        } else if(operacao == 3) {
            string_upper(str);
            printf("String convertida para maiusculas: %s\n", str);
        } else if(operacao == 4) {
            string_lower(str);
            printf("String convertida para minusculas: %s\n", str);
        } else if(operacao == 5) {
            string_reverse(str);
            printf("String invertida: %s\n", str);
        }
        printf("\n");
        print_menu();
    }

    return 0;
}