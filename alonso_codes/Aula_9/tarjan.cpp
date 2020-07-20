#include <iostream>

using namespace std;
// Ordem do Tarjan é n+m
Tarjan(G)
{
    // Primeiramente tem que zerar a porra toda 
    int ce = 0;
    int cc = 0;
    for (v em V)
    {
        expl[v] = 0;
        comp[v] = 0;
    }
    // Tatica pra fazer saltos
    for (v em V)
        if (expl[v] == 0)
            DFST(v);
}

DFST(v)
{
    // Entrou no DFST já altera a exploração
    expl[v] = ++ce;
    // Para todo no ramo vu não explorado, dale
    for (<v, u> em E if (expl[u] == 0))
    {
        // Chama de arvore
        tipo[<v, u>] = T;
        // Chama DFST no u
        DFST(u);
    }
    // Se o explu for maior, então é avanço, forward
    else if (expl[u] > expl[v])
        tipo[<v, u>] = F;
    // Se o explu for menor, e compu for diferente de zero
    // Então ele já foi visitado, é cruzamento
    else if (comp[u] > 0)
        tipo[<v, u>] = C;
    // Se explu for menor, e compu for zero
    // Então é retorno
    else tipo[<v, u>] = B;
    // Depois de classificar e ativar para todos vizinhos
    // Altera o comp
    comp[v] = ++cc;
}