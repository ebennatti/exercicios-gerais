#include <stdio.h>
#include "array.h"

int main() {
    Array *a = CriarArray();
    LerArray(a);

    int elementoBuscado = 0;
    scanf("%d", &elementoBuscado);
    OrdenarArray(a);
    if(BuscaBinariaArray(a, elementoBuscado) == -1)
        printf("Elemento %d não encontrado no array (-1).\n", elementoBuscado);
    else
        printf("Elemento %d encontrado no índice %d.\n", elementoBuscado, BuscaBinariaArray(a, elementoBuscado));

    DestruirArray(a);
    return 0;
}