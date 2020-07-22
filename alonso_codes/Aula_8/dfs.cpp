#include <iostream>

using namespace std;

// nada mudou
// <<< tentar entender melhor a ordem!!
int cont = 0;
desmarcar todos os vértices;

// Não tem raiz
DFS(s)
{
    // Marcar o cara
    marcar s;
    // meter a flag
    expl[s] = ++cont;
    // explorando s
    for (<s, v> em E)
    {
        // se ele estiver desmarcado, vai ter que marcar, isto é, chama função
        // repara que antes de terminar o looping, ele vai chamar outra recursão
        // então ele só termina o looping depois que terminarem todas recursões, ou seja
        // busca em profundidade :)
        if (v está desmarcado)
            DFS(v);
    }
}

DFS_iterative(s)
{
    desmarcar todos os vértices;
    // Aqui não é fila é pilha
    // a ideia é idêntica, a diferença é a flag que vai no while e que se usa pilha
    // pensar com  calma depoisenta
    stack P;
    int cont = 0;
    marcar s;
    push(P, s);
    while (!isEmpty(P))
    {
        curr = top(P);
        pop(P);
        expl[curr] = ++cont;
        // explorando curr
        for (<curr, v> em E)
        {
            if (v está desmarcado)
            {
                marcar v;
                push(P, v);
            }
        }
    }
}

TravessiaDFS(s)
{
    // mesmo esquema
    // enquanto houve v em V tal que haja algum desmarcado
    // caixa :)
    desmarcar todos os vértices;
    cont = 0;
    DFS(s);
    for (v em V)
    {
        if (v está desmarcado)
            DFS(v);
    }
}