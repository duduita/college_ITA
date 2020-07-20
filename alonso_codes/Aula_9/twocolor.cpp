#include <iostream>

using namespace std;

TwoColor(G)
{
    // Não precisa dos dois contadores
    // Agora são dois caracteres, 1 para cada cor
    // Zerou o expl
    for (v em V)
        expl[v] = 0;
    for (v em V)
        if (expl[v] == 0)
            // Isso é novo
            // Se retornar 0, e caixa
            if (DFSB(v, 2) == 0)
                return 0;
    return 1;
}
DFSB(v, color)
{
    // Primeira coisa é trocar de cor
    c = (color % 2) + 1;
    expl[v] = c; // troca cor
    // Se for arco de árvore
    for (<v, u> em E)
        if (expl[u] == 0)
        {
            // Já chama recursivo e mete o == porque é funcão int
            // Se for 0, é caixa
            if (DFSB(u, c) == 0)
                return 0;
        }
        // E se ele já tiver explorado
        // Se o da frente for da mesma cor.. caixa
        else if (expl[u] == c)
            return 0;
    // Se explorado ou não for de cor !=
    // Retorna 1 :)
    return 1;
}