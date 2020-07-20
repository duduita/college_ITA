#include <iostream>

using namespace std;
TarjanAC(r)
{
    // válido se for conexo e
    // não tiver laços ou
    // arestas repetidas
    int ce = 0;
    // Agora nao precisa se preocupar com filho
    for (v em V)
    {
        expl[v] = 0;
        pai[v] = null;
    }
    DFSAC(r); 
    // Nem com ficar verficando nada aqui
}
DFSAC(v)
{
    expl[v] = ++ce;
    // Isso aqui é novidade
    // Equivalente ao comp
    m[v] = expl[v];
    for (<v, u> em E)
        if (expl[u] == 0)
        {
            // grava o pai e chama a recursao
            pai[u] = v;
            DFSAC(u);
            // Macaco antigo
            m[v] = min{m[v], m[u]};
            // se m(u) == expl(u) é aresta de corte
            // pra ver isso só desenhando e olhe lá
            if (m[u] == expl[u])
                <v, u> é aresta de corte;
        }
        else // arestas de retorno
            if (u != pai[v])
            m[v] = min{m[v], expl[u]};
}