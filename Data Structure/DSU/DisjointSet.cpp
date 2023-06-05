const int MAX = 1e5 + 7;

struct Dsu {
    int lab[MAX];

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
        lab[u] += lab[v];
        lab[v] = u;
    }
} dsu;