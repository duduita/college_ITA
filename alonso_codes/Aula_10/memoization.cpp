int cnt = 0;

// moedas de troco com memoization
int makechange(vector<int> &moedas, int troco){
    cnt++;
    if (troco == 0) return 0;
    int q = troco;
    for (int i = 0; i < moedas.size(); ++i) {
        if (moedas[i] > troco) continue;
        q = min(q, 1 + makechange(moedas, troco-moedas[i]));
    }
    return q;
}

int main() {
    int troco = 45;
    vector<int> moedas = {1, 5, 10, 15};
    vector<bool> flags;
    vector<int> q;
    cout << makechange(moedas, troco) << endl;
    cout << "chamadas: " << cnt << endl;

    return 0;
}