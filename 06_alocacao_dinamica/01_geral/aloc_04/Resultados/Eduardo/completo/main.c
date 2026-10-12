#include <stdio.h>
#include "utils_char2.h"

int main() {
    char *string = CriaVetorTamPadrao();
    int tam = TAM_PADRAO;

    string = LeVetor(string, &tam);
    ImprimeString(string);
    LiberaVetor(string);

    return 0;
}