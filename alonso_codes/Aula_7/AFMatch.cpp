AFMatch()
{
    s = 0; // 0 é o estado inicial
    // Começa o loop que varre 0 a n-1
    for (i = 0; i < n; i++)
    {
        // Se ver a tabela fica fácil
        // É acessar a tabela, basicamente
        // As linhas são o estado e a coluna é a leitura
        s = AF[s, T[i]];
        if (s == m)       // último estado foi atingido
            return i - m; // posição de P em T
    }
    return -1; // P não foi encontrado
}