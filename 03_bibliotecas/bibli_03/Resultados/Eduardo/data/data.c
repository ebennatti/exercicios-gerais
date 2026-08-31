#include <stdio.h>
#include "data.h"

/**
 * @file data.h
 * @brief Biblioteca para manipulação de datas.
 * 
 * Esta biblioteca contém funções para verificar a validade de uma data, imprimir uma data por extenso,
 * verificar se um ano é bissexto, calcular o número de dias de um mês, comparar duas datas e calcular a
 * diferença em dias entre duas datas.
 * 
 */



/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano) {
    if(ano > 0) {
        if(mes >= 1 && mes <= 12) {
            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
                if(dia >= 1 && mes <= 31)
                    return 1;
                else 
                    return 0;
            } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                if(dia >= 1 && mes <= 30)
                    return 1;
                else 
                    return 0;
            } else {
                if(verificaBissexto(ano)) {
                    if(dia >= 1 && dia <= 29)
                        return 1;
                    else
                        return 0;
                } else {
                    if(dia >= 1 && dia <= 28)
                        return 1;
                    else
                        return 0;
                }
            }
        } else 
            return 0;
    } else
        return 0;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes) {
    if(mes == 1)
        printf("Janeiro");
    else if(mes == 2)
        printf("Fevereiro");
    else if(mes == 3)
        printf("Marco");
    else if(mes == 4)
        printf("Abril");
    else if(mes == 5)
        printf("Maio");
    else if(mes == 6)
        printf("Junho");
    else if(mes == 7)
        printf("Julho");
    else if(mes == 8)
        printf("Agosto");
    else if(mes == 9)
        printf("Setembro");
    else if(mes == 10)
        printf("Outubro");
    else if(mes == 11)
        printf("Novembro");
    else if(mes == 12)
        printf("Dezembro");
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano) {
    if(!(ano % 4)) {
        if(!(ano % 100)) {
            if(!(ano % 400)) 
                return 1;
            else   
                return 0;
        } else
            return 1;
    } else
        return 0;
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano) {
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        if(verificaBissexto(ano)) {
            return 29;
        } else  
            return 28;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if(ano1 > ano2) 
        return 1;
    else if(ano2 > ano1)
        return -1;
    else {
        if(mes1 > mes2)
            return 1;
        else if(mes2 > mes1) 
            return -1;
        else {
            if(dia1 > dia2)
                return 1;
            else if(dia2 > dia1)
                return -1;
            else 
                return 0;
        }
    }
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano) {
    int i = 0, dias_acumulados = 0;
    while(i != mes) {
        dias_acumulados += numeroDiasMes(i, ano);
        i++;
    }
    return dias_acumulados;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int dias_acumulados1 = 0, dias_acumulados2 = 0, d_acumulados = 0, i = 0;
    int data_menor = 0;
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
        //calcula dias passados do ano ate o dia especificado
        dias_acumulados1 = calculaDiasAteMes(mes1, ano1) + dia1;
        dias_acumulados2 = calculaDiasAteMes(mes2, ano2) + dia2;
        if(ano1 == ano2) {
            return dias_acumulados1 - dias_acumulados2;
        } else {
            //acumula anos inteiros
            while(i < (ano1 - ano2)) {
                if(verificaBissexto(ano2 + i)) {
                    d_acumulados += 366;
                } else {
                    d_acumulados += 365;
                }
                i++;
            }

            //calcula quantos dias faltam para fim do ano da data menor
            if(verificaBissexto(ano2)) {
                data_menor = 366 - dias_acumulados2;
            } else {
                data_menor = 365 - dias_acumulados2;
            }

            //soma tres partes, obtendo diferenca total
            return d_acumulados + dias_acumulados1 + data_menor;
        }
    } else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1) {
        //calcula dias passados do ano ate o dia especificado
        dias_acumulados1 = calculaDiasAteMes(mes1, ano1) + dia1;
        dias_acumulados2 = calculaDiasAteMes(mes2, ano2) + dia2;
        if(ano1 == ano2) {
            return dias_acumulados2 - dias_acumulados1;
        } else {
            //acumula anos inteiros
            while(i < (ano2 - ano1 - 1)) {
                if(verificaBissexto(ano1 + i)) {
                    d_acumulados += 366;
                } else {
                    d_acumulados += 365;
                }
                i++;
            }

            //calcula quantos dias faltam para fim do ano da data menor
            if(verificaBissexto(ano1)) {
                data_menor = 366 - dias_acumulados1;
            } else {
                data_menor = 365 - dias_acumulados1;
            }

            //soma tres partes, obtendo diferenca total
            return d_acumulados + dias_acumulados2 + data_menor;
        }
    } else
        return 0;
}

