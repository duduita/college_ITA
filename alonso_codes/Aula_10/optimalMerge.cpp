#include <bits/stdc++.h>
using namespace std;

vector<int> v(10);

// Declarando utilizando struct
struct TreeNode
{
    int valor;
    TreeNode *dir;
    TreeNode *esq;
};

// Declarando utilizando class
class TreeNode2 {

int valor;
TreeNode2 *esq;
TreeNode2 *dir;

public:

// Estudar isso com mais calma depois
node (void *v) {info = v; next = 0; }
void put_next (node *n) {next = n;}
node *get_next ( ) {return next;}
int *get_info ( ) {return valor;}
// Estudar isso com mais calma depois

};

int main()
{
    // Cria um heap
    make_heap(v.begin(), v.end());

    // Ou então, em pseudocódigo:
    // h = new heapMin();
    // h.build(v);

    for(i=1; i<k; i++){
        no = new TreeNode();
        no.esq = v.front();
        v.pop();
        no.dir = v.front();
        v.pop();
        no.valor = no.esq->valor + no.dir->valor;
        v.push_up(no);
    }
    return v.front();
}