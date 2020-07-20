#include <bits/stdc++.h>
using namespace std;

vector<unsigned int> denom{1, 5, 10};
unsigned value = 9;
vector<unsigned int> coins;
// só nao entendi o porquê do ultima
void f(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins)
{
    vector<unsigned int> quant;
    vector<unsigned int> ultima;
    quant.resize(value+1);
    ultima.resize(value+1);
    quant[0] = 0;
    ultima[0] = 0;
    unsigned int quantProv, ultProv, i, j;
    for (unsigned int cents = 1; cents <= value; cents++)
    {
        quantProv = cents;
        ultProv = 1;
        for (j = 0; j < denom.size(); j++)
        {
            if (denom[j] > cents)
                continue;
            if (quant[cents - denom[j]] + 1 < quantProv)
            {
                quantProv = quant[cents - denom[j]] + 1;
                ultProv = denom[j];
            }
        }
        quant[cents] = quantProv;
        ultima[cents] = ultProv;
    }
    coins.resize(denom.size(), 0);
    int temp = value;
    int denomtemp;
    while (temp > 0)
    {
        for (i = 0; i < denom.size(); i++)
        {
            if (denom[i] == ultima[temp])
            {
                denomtemp = i;
                break;
            }
        }
        coins[denomtemp] = coins[denomtemp] + 1;
        temp = temp - ultima[temp];
    }
    for (unsigned int i = 0; i < coins.size(); i++)
    {
        cout << coins[i] << endl;
    }
}

int main()
{
    f(denom, value, coins);
}
