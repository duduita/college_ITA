#include <iostream>

using namespace std;

Aciclicidade(G)
{
    // Criação de pilha paralela
    stack P;
    // Criação da booleana
    bool aciclico = true;
    // Resto é igual
    int ce = 0;
    int cc = 0;
    for (v em V)
    {
        expl[v] = 0;
        comp[v] = 0;
    }
    for (v em V)
        if (expl[v] == 0)
            DFSA(v);
    // if adicional, devido ao output
    if (aciclico)
        digrafo é acíclico;
    else
        digrafo é cíclico;
}

DFSA(v)
{
    expl[v] = ++ce;
    // Entrou, coloca na pilha paralela
    push(P, v);
    for (<v, u> em E)
        if (expl[u] == 0)
            DFSA(u);
        // Se tiver arco de retorno, é caixa
        else if (expl[u] < expl[v] && comp[u] == 0)
        {
            aciclico = false;
            // ciclo está em P
            // desde o topo até u
            stop;
        }
    // Saiu, tira da pilha paralela
    pop(P);
    comp[v] = ++cc;
}
