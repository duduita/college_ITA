#include <bits/stdc++.h>
using namespace std;
vector<unsigned int> denom{1, 2, 5};
unsigned int value = 3;
vector<unsigned int> coins;
int verifyDenom(const vector<unsigned int> &denom, unsigned int denomi);

void TrocoSolverGreedy(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins)
{
    unsigned int troco = 0;
    unsigned int i = 0, j = 0;
    unsigned int maior = 0;
    coins.resize(denom.size(), 0);
    while (i < denom.size() && troco < value)
    {
        maior = 0;
        for (j = 0; j < denom.size(); j++)
        {
            if (maior <= denom[j] && denom[j] <= (value - troco))
                maior = denom[j];
            cout << "maior: " << maior << endl;
        }
        while (troco < value)
        {
            troco = troco + maior;
            coins[verifyDenom(denom, maior)]++;
        }
        if (troco == value)
            return;
        troco = troco - maior;
        cout << "troco2: " << troco << endl;
        coins[verifyDenom(denom, maior)]--;
        i++;
    }

} //solve

int verifyDenom(const vector<unsigned int> &denom, unsigned int denomi)
{
    for (unsigned int i = 0; i < denom.size(); i++)
    {
        if (denom[i] == denomi)
            return i;
    }
}

int main()
{
    TrocoSolverGreedy(denom, value, coins);
    for (unsigned int i = 0; i < coins.size(); i++)
    {
        cout << "i: " << denom[i] << " " << coins[i] << endl;
    }
}
