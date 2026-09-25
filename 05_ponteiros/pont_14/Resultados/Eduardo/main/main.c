#include "tela.h"
#include "botao.h"

#include <stdio.h>

void executaSalvar() {
    //- Botao de SALVAR dados ativado!
    printf("- Executando o botao com evento de click\n");
    printf("- Botao de SALVAR dados ativado!\n");
}

void executaExcluir() {
    printf("- Executando o botao com evento de click\n");
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void executaOpcoes() {
    printf("- Executando o botao com evento de longo click\n");
    printf("- Botao de OPCOES ativado!\n");
}

int main() {
    Tela t = CriarTela(200, 400);
    Botao b[MAX_BOTOES];
    CriarTela(200, 400);
    b[0] = CriarBotao("Salvar", 12, "FFF", 1, executaSalvar);
    b[1] = CriarBotao("Excluir", 18, "000", 1, executaExcluir);
    b[2] = CriarBotao("Excluir", 18, "FF0000", 2, executaOpcoes);

    RegistraBotaoTela(&t, b[0]);
    RegistraBotaoTela(&t, b[1]);
    RegistraBotaoTela(&t, b[2]);

    DesenhaTela(t);

    OuvidorEventosTela(t);

    return 0;
}