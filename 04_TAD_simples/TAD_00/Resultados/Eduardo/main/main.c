#include <stdio.h>
#include "ponto.h"

int main() {
    Ponto p1, p2;
    scanf("%f %f", &p1.x, &p1.y);
    scanf("%f %f", &p2.x, &p2.y);

    printf("%g", pto_distancia(p1, p2));
    return 0;
}