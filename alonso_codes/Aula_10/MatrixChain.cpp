#include <bits/stdc++.h>
using namespace std;

int N[4][4];
int T[4][4];

int n = 4;

int main()
{
    // Primeiro mata os pequeno
    for (int i = 0; i < n; i++)
        N[i, i] = 0;
    // Essa parte nao peguei
    for (int b = 1; b < n; b++)
        for (int i = 0; i < n - b; i++)
        {
            int j = i + b;
            N[i, j] = +inf;
            T[i, j] = i;
            for (int k = i; k < j; k++)
            {
                int x = N[i, k] + N[k + 1, j] + d[i] * d[k + 1] * d[j + 1];
                if (N[i, j] > x)
                {
                    N[i, j] = x;
                    T[i, j] = k;
                }
            }
        }
    return N[0, n - 1];
}