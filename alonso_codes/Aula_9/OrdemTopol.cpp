#include <iostream>

using namespace std;

OrdemTopol(G)
{
    // supõe digrafo acíclico
    int ce = 0;
    int cc = 0;
    for (v em V)
    {
        expl[v] = 0;
        comp[v] = 0;
    }
    for (v em V)
        if (expl[v] == 0)
            DFSOT(v);
    // Sacada para já dar o output bonitinho (invertido)
    for (v em V)
        f[v] = n - comp[v] + 1;
}

DFSOT(v)
{
    expl[v] = ++ce;
    // Só interessa se for árvore
    for (<v, u> em E if (expl[u] == 0))
        DFSOT(u);
    comp[v] = ++cc;
}