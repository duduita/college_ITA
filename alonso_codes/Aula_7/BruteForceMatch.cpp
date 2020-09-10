BruteForceMatch()
{
    int m, i, n, j;
    // Primeiramente, Looping de 0 até n-m
    // Depois nao cabe mais
    for (i = 0; i <= n - m; i++)
    {
        // Zero o J
        j = 0;
        // Percorro casa a casa caso tenha experança
        // Importante que T[i+j] é novidade
        while (j < m && T[i + j] == P[j])
            j++;
        // Corre pro abraço
        if (j == m)
            return i; // P encontrado em T[i]
    }
    return -1; // P não foi encontrado
}