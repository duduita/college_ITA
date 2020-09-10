AFConstruct()
{
    // Começa o laço
    for (s = 0; s <= m; s++)
        // Tamanho do alfabeto vai influenciar na complexidade
        // Ponto fraco do algoritmo
        for (x em Σ)
        {
            // começa de s+2, porque é decrementado e o primeiro caso é s+1
            // lembrar que é s+1 porque o algoritmo vai pra frente e pra trás
            k = min{s + 2, m + 1}; // primeiro estado a ser testado
            // esse min é loucura
            // no último caso ele n pode testar P(s+1) = P(m+1)
            // aí ele testa P(m) (lembra do decremental)
            repeat
                k--;                              // testes em ordem decrescente
            until(Pk - 1 seja sufixo de Ps - 1x); // tempo Θ(m)
            AF[s, x] = k;
        }
}