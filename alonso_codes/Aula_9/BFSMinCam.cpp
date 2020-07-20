// Basta uma alteração da exploração em largura
// Para o caso de pesos iguais 
BFSMinCam(r)
{
    // Criamos a lista
    queue q;
    // Zeramos a condição inicial
    int ce = 0;
    // Para todos menos a raiz
    for (v em V - {r})
    {
        // Seta a distância infinita
        // Exploração 0
        d[v] = +infinito;
        expl[v] = 0;
    }
    // Incremente ce
    expl[r] = ++ce;
    // Seta 0
    d[r] = 0;  
    enqueue(q, r);
    while (!isEmpty(q))
    {
        // tira o cara da fila
        u = dequeue(q);
        // percorre os vizinhos
        for (<u, v> em E)
        {
            if (expl[v] == 0)
            {
                expl[v] = ++ce;
                d[v] = d[u] + 1;
                enqueue(q, v);
            }
        }
    }
}