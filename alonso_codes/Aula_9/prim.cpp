Prim(r)
{
    T recebe vazio;
    // árvore de espalhamento de custo mínimo
    U recebe{r};
    // vértices que já estão na árvore
    while (U != V)
    {
        <u, v> = aresta de custo mínimo | u pertence U e v pertence V - U;
        T recebe T união{<u, v>};
        // aqui, T contém só arestas
        U recebe U união{v};
    }
}