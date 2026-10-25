#include <stdio.h>
#include "missil.h"
#include "defesa.h"
#include "cidade.h"

int main() {
    tCidade c = CriaCidade();
    c = LeEntrada(c);
    ProcessaAtaques(c);
    ImprimeDados(c);
    LiberaCidade(c);
    return 0;
}