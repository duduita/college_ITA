#include <iostream>

using namespace std;

TarjanVC(r)
{
    // válido se for conexo e
    // não tiver laços ou
    // arestas repetidas
    // setando nula a variável de exploração
    int ce = 0;
    // para todo vertice em V
    for (v em V)
    {
        // Setar nulo flag de exploração
        expl[v] = 0;
        // setar o pai nulo e o numero de filhos nulo
        pai[v] = null;
        nfilhos[v] = 0;
        // Setar como nao é vértice de exploração
        VC[v] = false;
    }
    // Chama o cara
    DFSVC(r);
    // Se ele tiver mais de um filho é VC true
    VC[r] = (nfilhos[r] > 1);
    // Para o restante começa
    for (v em V - {r})
    {
        p = pai[v];
        // o numero m do filho é maior ou igual a exploracao do pai
        // isso aqui só pra pra ver quando se faz o desenho
        VC[p] = VC[p] || (m[v] >= expl[p]);
    }
    // Varre tudao
    for (v em V)
        if (VC[v])
            // Corre pro abraço
            v é vértice de corte;
}

DFSVC(v)
{
    // incrementa o exploração
    expl[v] = ++ce;
    // m pega o exploração (coisa comum para variável secundária)
    m[v] = expl[v];
    for (v, u > em E)
        if (expl[u] == 0)
        {
            // aumenta o contador
            pai[u] = v;
            nfilhos[v]++;
            // chamar a recursao
            DFSVC(u);
            // faz a verificação óbvia
            m[v] = min{m[v], m[u]};
        }
        else // arestas de retorno
            if (u != pai[v])
            m[v] = min{m[v], expl[u]};
}