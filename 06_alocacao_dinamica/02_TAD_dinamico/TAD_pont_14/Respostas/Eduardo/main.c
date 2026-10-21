#include "nba.h"
#include "franquia.h"
#include "partida.h"

int main() {
    tNBA nba = CriaNBA();
    RodaNBA(nba);
    ImprimeRelatorioNBA(nba);
    LiberaNBA(nba);
    return 0;
}