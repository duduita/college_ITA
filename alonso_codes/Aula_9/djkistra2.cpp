// Ele nao detalhou, entao caguei
Dijkstra2(u)
{
    for (v em V – {u})
        d[v] = +infinito;
    d[u] = 0;
    S recebe{u};
    while (S nao eh vazio)
    {
        selecionar j pertencente S;
        S recebe S – {j};
        for (<j, w> em E)
            if (d[w] > d[j] + cjw)
            {
                d[w] = d[j] + cjw;
                pred[w] = j;
                S recebe S uniao {w};
                // w volta para S
            }
    }