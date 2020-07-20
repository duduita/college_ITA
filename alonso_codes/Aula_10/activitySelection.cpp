// aprendendo bibliotecas :)
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

// aprender a escrever isso
using namespace std;

// declarando vetor de pair
typedef pair<int, int> Pair;
vector<Pair> v(10);

// declarando função que retorna fila
queue<int> activitySelection()
{
    v = sort(v, v.second);
    queue<int> q;
    q.push(1);
    int j = 1;
    for(int i=2; i<=n; i++){
        if(v[i].first > v[j].second){
            q.push(i);
            j = i;
        }
    }
    return q;
}

// sem main, não roda :)
int main(){
    cout << "foi";
}