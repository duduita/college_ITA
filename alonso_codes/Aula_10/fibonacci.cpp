#include <bits/stdc++.h>
using namespace std;

vector<int> F(10);

int n = F.size();

int fibonacci(int n)
{
    F[0] = 1;
    F[1] = 1;
    for (i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}