#include <TspSolver.h>
using namespace std;
#include <vector>
#include <bits/stdc++.h>
#include <queue>
#define INF 1000000000
#include <set>

// Variáveis globais
typedef pair<int, int> iPair;


// Busca em profundidade
void DFS1(int s, vector<int> &marcado, vector<int> &percourse, set<int> MST[])
{
    marcado[s] = 1;
    percourse.push_back(s+1);
    for (auto elemento : MST[s])
    {
        if (!marcado[elemento])
            DFS1(elemento, marcado, percourse, MST);
    }
    
}

// Classe do Grafo
class Graph
{
    int N;
    list<iPair> *adj;

public:
    Graph(int N);
    // Adiciona origem destino e peso
    void addCity(int u, int v, int w);
    void primMST(set<int> MST[]);
};

Graph::Graph(int N)
{
    this->N = N;
    adj = new list<iPair>[N];
}

void Graph::addCity(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primMST(set<int> MST[])
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> heap;
    int raiz = 0;
    // vetor de tamanho n e módulo INF
    vector<int> dist;
    dist.resize(N, INF);
    // vetor de tamanho n e módulo -1
    vector<int> parent;
    parent.resize(N, -1);
    // vetor de marcação boleano
    vector<bool> inMST;
    inMST.resize(N, false);

    heap.push(make_pair(0, raiz));
    dist[raiz] = 0;

    // Como visto na aula 9, usou-se heap para agilizar o PRIM
    // visto que se deseja achar o mínimo em um conjunto
    // Coloco o extract da fila da prioridade (heap min) é mais rápido
    while (!heap.empty())
    {

        int u = heap.top().second;
        heap.pop();

        inMST[u] = true;
        list<iPair>::iterator i;

        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {

            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && dist[v] > weight)
            {
                dist[v] = weight;
                heap.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
    // Usou-se a estrutura SET para facilitar esse insert (pois ela já ordenada)
    for (int i = 1; i < N; i++)
    {
        MST[i].insert(parent[i]);
        MST[parent[i]].insert(i);
    }
}

void TspSolver::solve(TspReader &tr, vector<int> &percourse)
{
    // Pega os dados do Tr
    // Cria um vector city, armazena os valores de Tr
    // Pega o número de cidades e passa para N

    vector<City> cidades;
    int N = tr.getNumCities();
    cidades.resize(N);
    tr.copyCitiesVector(cidades);
    set<int> MST[N];

    // Construtora do grafo
    Graph g(N);
    // Vetor de Flags
    vector<int> marcado(N, 0);

    // Coletando as cidades e colocando no grafo
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a = cidades[i].getId();
            int b = cidades[j].getId();
            int c = cidades[i].disti(cidades[j]);
            g.addCity(a - 1, b - 1, c);
        }
    }

    // Chamando o Prim
    g.primMST(MST);

    // Preencher o percourse
    DFS1(0, marcado, percourse, MST);
    
}