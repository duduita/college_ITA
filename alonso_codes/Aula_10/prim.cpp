#include <algorithm>
using namespace std;

#define INF 1000000000

N = 4;
// Matrizona
int g[N][N];
// Distancia dos cara
int dist[N];
// Quais estao marcado
int marc[N];

int main()
{
    // Retorna o custo de uma MST do grafo representado por g.h
    // botou geral pro infinito
    for (int i = 0; i < N; i++)
        dist[i] = INF;
    dist[0] = 0;

    int curr = 0;
    int custo = 0;
    while (curr != -1)
    {
        marc[curr] = 1;
        custo += dist[curr];

        for (int i = 0; i < N; i++)
        {
            if (g[curr][i])
                dist[i] = min(dist[i], g[curr][i]);
        }

        curr = -1;
        int min_dist = INF;
        for (int i = 0; i < N; i++)
        {
            if (!marc[i] && dist[i] < min_dist)
            {
                curr = i;
                min_dist = dist[i];
            }
        }
    }
    return custo;
}