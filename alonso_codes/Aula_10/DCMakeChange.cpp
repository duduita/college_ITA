#include <bits/stdc++.h>
using namespace std;

vector<unsigned int> denom{1, 5, 10};
unsigned int value = 10;
vector<unsigned int> coins;
vector<unsigned int> ultima;
unsigned int TrocoSolverDivConquer2(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins, vector<unsigned int> &ultima);

int verifyDenom(const vector<unsigned int> &denom, unsigned int denomi)
{
    for (unsigned int i = 0; i < denom.size(); i++)
    {
        if (denom[i] == denomi)
            return i;
    }
    return 0;
}

void TrocoSolverDivConquer(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins)
{
    coins.resize(denom.size(), 0);
    ultima.resize(value + 1, 0);
    unsigned int q = TrocoSolverDivConquer2(denom, value, coins, ultima);
    unsigned int temp = value;
    while (q != 0)
    {
        coins[verifyDenom(denom, ultima[temp])]++;
        temp -= ultima[temp];
        q--;
    }
    return;
}

unsigned int TrocoSolverDivConquer2(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins, vector<unsigned int> &ultima)
{
    if (value == 0)
        return 0;
    unsigned int q = value;
    ultima[0] = denom[0];
    unsigned int ultProv = 1;
    for (unsigned int i = 0; i < denom.size(); i++)
    {
        if (denom[i] > value)
            continue;
        unsigned int temp = TrocoSolverDivConquer2(denom, value - denom[i], coins, ultima);
        if (q > (1 + temp))
        {
            q = 1 + temp;
            ultProv = denom[i];
        }
    }
    ultima[value] = ultProv;
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
