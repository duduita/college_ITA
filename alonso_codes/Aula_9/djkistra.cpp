 Dijkstra(u)
{
    d[u] = 0; // vértice inicial u: distância nula
    for (v em V – {u})
        d[v] = +infinito;
    // demais vértices : distância +infinita
    S recebe V; (vértice com distâncias provisória)
    // S : vértices com distância provisória 
    while S nao eh vazio
    {
        // Isso aqui é com heap, porque eu quero o mínimo de um conjunto
        selecionar j tal que d[j] == min{d[i]}, onde i pertence a S;
        S recebe (S – {j}); // j passa a ter distância definitiva
        // importante, w pertence a S (ele nao tem distancia definitiva ainda)
        for (<j, w> em E, onde w em S)
            if (d[w] > d[j] + cjw)
            {
                // dar modifyer no heap
                // tenho que saber a posicao desse vértice no heap
                // ter um vetor auxiliar que nós dá a cada vértice do heap a sua posicao no heap
                d[w] = d[j] + cjw;
                pred[w] = j;
            }
    }
