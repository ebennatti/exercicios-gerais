#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"


/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao() {
    int n = 0;
    tEleicao e;
    e.votosBrancosGovernador = 0;
    e.votosBrancosPresidente = 0;
    e.votosNulosGovernador = 0;
    e.votosNulosPresidente = 0;
    e.totalGovernadores = 0;
    e.totalPresidentes = 0;
    e.totalEleitores = 0;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        tCandidato c;
        char cargo;
        c = LeCandidato();
        cargo = ObtemCargo(c);
        if(cargo == 'P') {
            e.presidentes[e.totalPresidentes] = c;
            e.totalPresidentes++;
        } else if(cargo == 'G') {
            e.governadores[e.totalGovernadores] = c;
            e.totalGovernadores++;
        }
    }
    if(e.totalPresidentes > MAX_CANDIDATOS_POR_CARGO || e.totalGovernadores > MAX_CANDIDATOS_POR_CARGO) {
        printf("ELEICAO ANULADA\n");
        exit(1);
    }
    
    return e;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao) {
    int n;
    scanf("%d\n", &n);
    eleicao.totalEleitores = n;
    if(eleicao.totalEleitores > MAX_ELEITORES) {
        printf("ELEICAO ANULADA\n");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        int achou = 0;
        eleicao.eleitores[i] = LeEleitor();
        for(int j = 0; j < i; j++) {
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])) {
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }
        if(ObtemVotoPresidente(eleicao.eleitores[i]) == 0)
            eleicao.votosBrancosPresidente++;
        else {
            for(int j = 0; j < eleicao.totalPresidentes; j++) {
                if(VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(eleicao.eleitores[i])) && !achou) {
                    eleicao.presidentes[j].votos++;
                    achou = 1;
                }
            }
            if(!achou)
                eleicao.votosNulosPresidente++;
        }
        achou = 0;
        if(ObtemVotoGovernador(eleicao.eleitores[i]) == 0)
            eleicao.votosBrancosGovernador++;
        else {
            for(int j = 0; j < eleicao.totalGovernadores; j++) {
                if(VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(eleicao.eleitores[i])) && !achou) {
                    eleicao.governadores[j].votos++;
                    achou = 1;
                }
            }
            if(!achou)
                eleicao.votosNulosGovernador++;
        }
    }
    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao) {

    //PRESIDENTE
    printf("- PRESIDENTE ELEITO: ");
    int maisVotos = -1;
    int idxMaisVotado = -1;
    for(int i = 0; i < eleicao.totalPresidentes; i++) {
        if(ObtemVotos(eleicao.presidentes[i]) > maisVotos) {
            maisVotos = ObtemVotos(eleicao.presidentes[i]);
            idxMaisVotado = i;
        }
    }
    int empate = 0;
    for(int i = 0; i < eleicao.totalPresidentes; i++) {
        if(ObtemVotos(eleicao.presidentes[idxMaisVotado]) == ObtemVotos(eleicao.presidentes[i]) && idxMaisVotado != i) {
            empate = 1;
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            break;
        }
    }
    if(!empate && ObtemVotos(eleicao.presidentes[idxMaisVotado]) > eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente) {
        float percentual = CalculaPercentualVotos(eleicao.presidentes[idxMaisVotado], eleicao.totalEleitores);
        ImprimeCandidato(eleicao.presidentes[idxMaisVotado], percentual);
    }else if(!empate && ObtemVotos(eleicao.presidentes[idxMaisVotado]) < eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente) {
        printf("SEM DECISAO\n");
    }


    //GOVERNADOR
    printf("- GOVERNADOR ELEITO: ");
    maisVotos = -1;
    idxMaisVotado = -1;
    for(int i = 0; i < eleicao.totalGovernadores; i++) {
        if(ObtemVotos(eleicao.governadores[i]) > maisVotos) {
            maisVotos = ObtemVotos(eleicao.governadores[i]);
            idxMaisVotado = i;
        }
    }
    empate = 0;
    for(int i = 0; i < eleicao.totalGovernadores; i++) {
        if(ObtemVotos(eleicao.governadores[idxMaisVotado]) == ObtemVotos(eleicao.governadores[i]) && idxMaisVotado != i) {
            empate = 1;
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            break;
        }
    }
    if(!empate && ObtemVotos(eleicao.governadores[idxMaisVotado]) > eleicao.votosNulosGovernador + eleicao.votosBrancosGovernador) {
        float percentual = CalculaPercentualVotos(eleicao.governadores[idxMaisVotado], eleicao.totalEleitores);
        ImprimeCandidato(eleicao.governadores[idxMaisVotado], percentual);
    }else if(!empate && ObtemVotos(eleicao.governadores[idxMaisVotado]) < eleicao.votosNulosGovernador + eleicao.votosBrancosGovernador) {
        printf("SEM DECISAO\n");
    }

    printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosGovernador + eleicao.votosNulosPresidente, eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente);
}