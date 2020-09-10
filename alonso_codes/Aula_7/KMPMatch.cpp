KMPMatch()
{
    FailureFunction(); // Veremos que gasta tempo Θ(m)
    i = 0;
    j = 0;
    while (i < n)
        if (T[i] == P[j])
            if (j == m - 1)   // Se o J sobreviveu até lá, então é porque achou
                return i - j; // Retorno a posição do ínicio da ocorrência, por isso -j
            else              // Se não continua percorrendo
            {
                i++;
                j++;
            }
            // Se quebrou o padrão, atualiza o j  com o F[j-1]
        else 
            if (j != 0)
                j = F[j - 1];
            else
                i++;
    return -1;
}