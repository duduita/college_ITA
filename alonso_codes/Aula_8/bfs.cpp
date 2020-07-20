#include <iostream>

using namespace std;
// Ordem é O(n+m)
// Ideia
// Marcar, mete flag, poe na fila. Tira da fila, para todo v ligado a ele, marcar, mete flag, poe  na  fila. Tir dafila, ...
// Para o caso de dígrafos
TravessiaBFS(s)
{
    // nada mudou
    desmarcar todos os vértices;
    cont = 0;
    // chama o BFS
    BFS(s);
    // Sacada, para todos os vértices
    for (v em V)
    {
        // se tiver desmarcado, ele reinicia
        // aí ele atravessa
        if (v está desmarcado)
            BFS(v);
    }
}

// Como não tem raíz, tem que ter um input
void BFS(s)
{
    // Primeiro desmarco todos os vértices
    desmarcar todos os vértices;
    // Apenas uma flagzinha pra dizer a ordem de exploração
    int cont = 0;
    // Crio a fila
    queue q;
    // Marco o s
    marcar s;
    // socando a flag
    expl[s] = ++cont;
    //  Coloco s na fila
    enqueue(q, s);
    // Enquanto houver alguém na fila
    while (!isEmpty(q))
    {
        // Tiro o s da fila
        curr = dequeue(q);
        // explorando curr
        for (<curr, v> em E)
        {
            // Para cada cara do vértice, se ele tiver desmarcado
            if (v está desmarcado)
            {
                // Marcar V
                marcar v;
                // socando a flag
                expl[v] = ++cont;
                // Colocar na fila
                enqueue(q, v);
            }
        }
    }
}