#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"
#include "movel.h"
#include "vector.h"

int main() {
    int n;
    Fila *f = FilaConstruct();
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++) {
        char op[20];
        scanf("%s ", op);
        if(!strcmp(op, "ENTRADA")) {
            tMovel *m = LeMovel();
            FilaPush(f, m);
        } else {
            tMovel *t = (tMovel *)FilaPop(f);
            ImprimeMovel(t);
            DestroiMovel(t);
        }
    }

    FilaDestroy(f, DestroiMovel);
    return 0;
}