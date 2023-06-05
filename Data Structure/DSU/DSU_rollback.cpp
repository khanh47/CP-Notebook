// Tested:
// - (dynamic connectivity) https://codeforces.com/gym/100551/problem/A
// - (used for directed MST) https://judge.yosupo.jp/problem/directedmst

struct Dsu {
    int lab[MAX];
    stack<pair<int, int>> st1, st2;

    void init(){
        FOR (i, 1, numNode)
            lab[i] = -1;
    }

    int Find(int u){
        return (lab[u] < 0 ? u : Find(lab[u]));
    }

    void Merge(int u, int v){
        u = Find(u);
        v = Find(v);
        if (u == v)
            return;
        if (lab[u] > lab[v])
            swap(u, v);
        st1.push({u, lab[u]});
        st2.push({v, lab[v]});
        lab[u] += lab[v];
        lab[v] = u;
    }

    void rollBack(int num){
        while (num--){
            auto u = st1.top(); st1.pop();
            auto v = st2.top(); st2.pop();
            lab[u.fi] = u.se;
            lab[v.fi] = v.se;
        }
    }
} dsu;