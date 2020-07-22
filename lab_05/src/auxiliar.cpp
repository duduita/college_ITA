#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#include <set>

typedef pair<int, int> iPair;
int k = 0;
void DFS1(int s, vector<int> &marcado, vector<int> &percourse, set<int> MST[])
{
    marcado[s] = 1;
    percourse.push_back(s + 1);
    k++;
    /*for (std::set<int>::iterator it = MST[s].begin(); it != MST[s].end(); ++it)
    {
        if (!marcado[*it])
            DFS1(*it, marcado, percourse, MST);
*/
    for (auto elemento : MST[s])
    {
        if (!marcado[elemento])
        {
            cout << endl
                 << "elemento: " << elemento;
            DFS1(elemento, marcado, percourse, MST);
        }
    }
}

class City
{
public:
    City() : x(0), y(0), id(0){};
    City(int x_, float y_, float id_) : x(x_), y(y_), id(id_){};

    int disti(City &c)
    {
        return (int)round(dist(c));
    }

    float dist(City &c)
    {
        return (sqrt((x - c.x) * (x - c.x) + (y - c.y) * (y - c.y)));
    }

    float getx() const { return x; }
    float gety() const { return y; }
    int getId() const { return id; }

    void copy(City &c)
    {
        x = c.getx();
        y = c.gety();
        id = c.getId();
    }

private:
    float x;
    float y;
    int id;
};
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
    vector<int> dist(N, INF);
    // vetor de tamanho n e módulo -1
    vector<int> parent(N, -1);
    // vetor de marcação boleano
    vector<bool> inMST(N, false);

    heap.push(make_pair(0, raiz));
    dist[raiz] = 0;

    while (!heap.empty())
    {
        // cout << "oi" << endl;

        int u = heap.top().second;
        heap.pop();
        //cout << adj[u].begin() << endl;
        //out << adj[u].end() << endl;

        inMST[u] = true;
        list<iPair>::iterator i;
        //cout << "oi2" << endl;

        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            //cout << "oi3" << endl;

            int v = (*i).first;
            int weight = (*i).second;
            //cout << "oi" << endl;

            if (inMST[v] == false)
                if (dist[v] > weight)
                {
                    dist[v] = weight;
                    heap.push(make_pair(dist[v], v));
                    parent[v] = u;
                    //cout << "oi" << endl;
                }
                else if (dist[v] == weight)
                {
                    if (parent[v] < parent[u])
                    {
                        heap.push(make_pair(dist[v], v));
                        parent[v] = u;
                    }
                    if (parent[v] == parent[u])
                    {
                        
                    }
                }
        }
    }
    // Print edges of MST using parent array
    for (int i = 1; i < N; ++i)
    {
        printf("pai: %d - filho: %d\n", parent[i], i);
        MST[i].insert(parent[i]);
        MST[parent[i]].insert(i);
    }
}

// Driver program to test methods of graph class
int main()
{
    // Cria cidades (identica do pdf do lab)
    vector<City> cidades;
    City c1(2, 5, 1);
    City c2(2, 3, 2);
    City c3(1, 2, 3);
    City c4(4, 5, 4);
    City c5(5, 4, 5);
    City c6(4, 3, 6);
    City c7(6, 3, 7);
    City c8(3, 1, 8);
    City c9(3, 2, 9);
    // Poe no vetor cidades
    cidades.push_back(c1);
    cidades.push_back(c2);
    cidades.push_back(c3);
    cidades.push_back(c4);
    cidades.push_back(c5);
    cidades.push_back(c6);
    cidades.push_back(c7);
    cidades.push_back(c8);

    // Cria o grafo e a MST até N+1
    int N = cidades.size();
    Graph g(N);
    set<int> MST[N];

    vector<int> marcado(N, 0);
    vector<int> percourse;
    percourse.resize(N, 0);
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
    g.primMST(MST);

    for (int i = 0; i < N; i++)
    {
        for (std::set<int>::iterator it = MST[i].begin(); it != MST[i].end(); ++it)
            std::cout << ' ' << *it;
        cout << endl;
    }
    DFS1(0, marcado, percourse, MST);
    for (int i = 0; i < N; i++)
    {
        cout << endl
             << percourse[i];
    }
    return 0;
}