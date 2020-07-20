#include <iostream>

using namespace std;
// Falta fazer recursivo
// Tem duas sacadinhas maldosas
void TopSort()
{
    // Iniciar o contador
    int counter = 0;
    // Para todos os vértices
    for (v em V)
        // Cálcula o valor do cara
        calcular indegree(V);
    // Cria a lista
    queue q;
    // Para todos os vértices
    for (v em V)
        // Se o vértice é nulo
        if (indegree(v) == 0)
            // Taca na fila
            q.enqueue(v);
    // Enquanto houver alguém na fila
    while (!q.isEmpty())
    {
        // Desempacota a fila
        v = q.dequeue();
        // Coloca a flagzinha cachorra
        f[v] = ++counter;
        // Para todos os caras que tem ligação com ele
        for (<v, w> em E)
            // Se subtrai 1 e vê se tem zero
            // <<<< sacadinha maldosa
            if (--indequeue(w) == 0)
                // Se tiver, põe na fila
                q.enqueue(w);
    }
    // Verificar se o gráfico é ciclico
    // <<<< sacadinha maldosa
    if (counter != n)
        print("graf é ciclico");
}

