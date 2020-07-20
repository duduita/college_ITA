#include <bits/stdc++.h>
using namespace std;

vector<unsigned int> denom{1, 5, 10};
unsigned int value = 10;
vector<unsigned int> coins;
unsigned int TrocoSolverDivConquer2(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins, unsigned int valueOrig);

void TrocoSolverDivConquer(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins)
{
    TrocoSolverDivConquer2(denom, value, coins, value);
    return;
}

unsigned int TrocoSolverDivConquer2(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins, unsigned int valueOrig)
{
    coins.resize(denom.size(), 0);
    if (value == 0)
        return 0;
    unsigned int q = value;
    coins.resize(denom.size(), 0);
    for (unsigned int i = 0; i < denom.size(); i++)
    {
        coins.resize(denom.size(), 0);
        if (denom[i] > value)
        {
            continue;
        }
        coins[i]--;
        q = min(q, 1 + TrocoSolverDivConquer2(denom, value - denom[i], coins, valueOrig));
        coins[i]++;
    }
    coins.resize(denom.size(), 0);
    return q;
}

int main()
{
    TrocoSolverDivConquer(denom, value, coins);
    for (unsigned int i = 0; i < coins.size(); i++)
    {
        cout << "i: " << denom[i] << " " << coins[i] << endl;
    }
}
