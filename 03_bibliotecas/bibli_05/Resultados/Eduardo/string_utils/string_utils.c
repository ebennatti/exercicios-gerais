#include "string_utils.h"
/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str) {
    int i = 0;
    while(str[i] != '\0') 
        i++;

    return i;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest) {
    int size = string_length(src) + 1;
    for(int i = 0; i < size; i++) {
        if(i == size - 1)
            dest[i] = '\0';
        else
            dest[i] = src[i];
    }
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str) {
    int size = string_length(str);
    for(int i = 0; i < size; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] -= 32;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str) {
    int size = string_length(str);
    for(int i = 0; i < size; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') 
            str[i] += 32;
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str) {
    int size = string_length(str);
    char temp;
    for(int i = 0; i < size/2; i++) {
        temp = str[size - 1 - i];
        str[size - 1 - i] = str[i];
        str[i] = temp;
    }
    return;
}
