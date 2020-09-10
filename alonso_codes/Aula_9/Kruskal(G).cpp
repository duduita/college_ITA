Kruskal(G)
{
    T <- vazio;
    A <- vetor com as arestas em ordem crescente de custo;
    // Cria n componentes uma para cada vértice
    // Ex: A, B, C ...
    criar n componentes com os n vértices isolados;
    // Ou acabou o número de arestas ou a arvore ta cheia
    for (i = 1; i <= m && |T| < n - 1; i++)
    {
        // Pega a aresta do vetor
        <u, v> = A[i];
        // 1 find: se elas já nao estao na mesma componente
        if (u e v não estão na mesma componente)
        {
            // A áravore ganha ela
            T <- T U {<u, v>};
            // Une as componentes que contém u e v
            unir as componentes que contêm u e v;
        }
    }
}