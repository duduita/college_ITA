BoyerMooreMatch()
{
    // Pré-processamento
    // -1 p/ geral
    for (k = 0; k < |Σ| ; k++)
        L[k] = -1;
    // genial esse L[P[k]]
    for (k = 0; k < m; k++)
        L[P[k]] = k;
    // começando no final
    i = m - 1;
    j = m - 1;
    repeat
    {
        if (T[i] == P[j])
            if (j == 0) // palavra toda entrou
                return i; // inicio da palavra
            else
            { // Se não decrementa
                i--;
                j--;
            }
        else // se não bater 
        {
            x = L[T[i]];
            // se T[i] = -1, então 1 + x = 0, logo, i = i + m -> desloca m
            // se x à esq, então, 1+x < j, logo, i = i + m - 1 - x -> logo, alinha
            // se x à dir, então 1 + x > j, logo, i = i + m - j -> logo, passinho
            i += m - min{j, 1 + x};
            j = m - 1;
        }
    // Até que i seja maior que n
    }
    until(i > n - 1);
    return -1;
}
