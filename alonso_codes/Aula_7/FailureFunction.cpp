// Parcial
FailureFunction()
{
    F[0] = 0;
    j = 0; // índice que percorre os prefixos
    i = 1; // índice que percorre os sufixos

    // Enquanto i for menor que a palavra. 
    // i  vai de 1 até m-1
    while (i < m)
        // Se combinaram, continua!
        // Incrementando de trás pra frente e de frente pra trás
        if (P[i] == P[j]) // já combinaram j+1 caracteres
            F[i++] = ++j;
        // DÚVIDA
        else if (j == 0)
            F[i++] = 0;
        else
            j = F[j - 1]; // uso “recursivo” de F
}
// Como é um decremento, será executado até m - 1 vezes 
// j é incrementado m - 1 vezes no máximo