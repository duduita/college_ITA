Knapsack01()
{
    // fazer a matriz ajuda muito e é bem fácil
    // Primeiro a gente zera todos os B(0,0)
    for (i = 0; i <= c; i++)
        B[0, i] = 0; // nenhum item é considerado
    // Agora eu varro a tabela, matrix
    for (k = 1; k <= n; k++)     // incremento nos itens
        for (i = 0; i <= c; i++) // incremento na capacidade
            // Se não couber, a solução ótima é a k-1
            if (w[k] > i)
                B[k, i] = B[k - 1, i];
            else
                // Se couber, ou é a k-1, ou é a que eu adiciono ele
                B[k, i] = max{B[k - 1, i], B[k - 1, i - w[k]] + p[k]};
    // Retorno o c (cap final) e o n, isto é, o último elemento da matriz
    return B[n, c];
}

VetorX()
{
    r = c;       // peso
    s = B[n, c]; // lucr
    for (i = n; i > 0; i--)
        if (B[i - 1, r] == s)
            X[i] = 0; // i
        else
        {
            X[i] = 1; // i
            s -= p[i];
            r -= w[i];
        }
}