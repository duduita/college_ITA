#include <iostream>

using namespace std;
// A sacada é que há duas trocas
// Uma quando após a visitação inicial (a troca óbvia)
// E outra é quando o vértice quer visitar outro que nao está na pilha
// Assim troca-se o CFC dele com o exploração do outro (o menor desses)
TarjanCFC(G)
{
    stack P;
    int ce = 0;
    for (v em V)
        expl[v] = 0;
    for (v em V)
        if (expl[v] == 0))
        DFSCFC(v);
}
DFSCFC(v)
{
    expl[v] = ++ce;
    push(P, v);
    // Isso é novidade
    // É Equivalente ao compl
    // Só que funciona para o CFC
    CFC[v] = expl[v];
    for (<v, u> em E)
        if (expl[u] == 0))
            {
                DFSCFC(u);
                // Ele verifica se o CFC do filho é menor
                // Se sim, atualiza
                CFC[v] = min{CFC[v], CFC[u]};
            }
        // Esse caso é mais chatinho
        // É o caso que o CFC do F é maior que o expl do B
        // Então o F atualiza o CFC para o número menor
        else if (u em P)
            CFC[v] = min{CFC[v], expl[u]};
    // Quando ele chega em quem começou
    if (CFC[v] == expl[v])
        // Vai desempilhando até que se chega no v
        // importante! while !x=v
        do
        {
            x = top(P);
            pop(P);
        } while (x != v);
}