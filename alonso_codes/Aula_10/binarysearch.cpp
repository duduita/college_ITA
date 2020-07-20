
#include <iostream>
#include <vector>
using namespace std;

vector <int> v {1,2,3,4,5,6};

bool binarySearch(int l, int r, int x)
{
    if (r < l)
        return false;
    int q = (l + r) / 2;
    if (v[q] == x)
        return true;
    if (v[q] > x)
        return binarySearch(l, q - 1, x);
    return binarySearch(q + 1, r, x);
}

int main()
{
    cout << binarySearch(0, 6, 0);
}