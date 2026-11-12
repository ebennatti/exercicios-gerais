#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tadgen.h"

int main() {
    int type, num;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: \n");
    scanf("%d %d\n", &type, &num);
    tGeneric *g = CriaGenerico(type, num);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);

    return 0;

}