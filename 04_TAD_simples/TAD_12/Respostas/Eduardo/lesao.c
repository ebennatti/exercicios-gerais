#include <string.h>
#include <stdio.h>
#include "lesao.h"

/*
Função que cria uma lesão a partir dos parâmetros fornecidos.
@param cartaoSus: Cartão SUS do paciente associado à lesão.
@param id: Identificador único da lesão.
@param diagnostico: Diagnóstico da lesão.
@param regiao: Região do corpo onde a lesão está localizada.
@param malignidade: Indicador de malignidade (1 para maligna, 0 para benigna).
@return A lesão criada.
*/
Lesao criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade) {
    Lesao l;
    strcpy(l.cartaoSus, cartaoSus);
    strcpy(l.id, id);
    strcpy(l.diagnostico, diagnostico);
    strcpy(l.regiao, regiao);
    l.malignidade = malignidade;
    return l;
}

/*
Função que lê os dados de uma lesão a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return A lesão lida.
*/
Lesao lerLesao() {
    Lesao l;
    scanf("%[^\n]\n", l.cartaoSus);
    scanf("%[^\n]\n", l.id);
    scanf("%[^\n]\n", l.diagnostico);
    scanf("%[^\n]\n", l.regiao);
    scanf("%d\n", &l.malignidade);
    return l;
}

/*
Função que obtém o cartão SUS associado a uma lesão.
@param l: A lesão da qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
void getCartaoSusLesao(Lesao l, char *cartaoSus) {
    strcpy(cartaoSus, l.cartaoSus);
}

/*
Função que verifica se uma lesão é cirúrgica (maligna).
@param l: A lesão a ser verificada.
@return 1 se a lesão for cirúrgica (maligna), 0 caso contrário.
*/
int verificaCirurgicaLesao(Lesao l) {
    if(l.malignidade > 50)
        return 1;
    else 
        return 0;
}

/*
Função que imprime o identificador de uma lesão.
@param l: A lesão cuja identificação será impressa.
*/
void imprimeIdLesao(Lesao l) {
    printf("%s", l.id);
}