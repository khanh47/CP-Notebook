// Tested:
// - http://codeforces.com/gym/100739/problem/G
//
// Notes:
// - Index from 1
// query range use getRange(a, b)
// query point use getPoint(a, b) (dep[a] < dep[b] and a is ancestor of b)

const int MAX = 1e5 + 7;

int sz[MAX], pos[MAX], heavy[MAX], head[MAX], chain[MAX], dep[MAX], par[MAX];
int cnt, nChain;
struct Hld {
    void build(int u){
        if (!head[nChain])
            head[nChain] = u;
        chain[u] = nChain;
        pos[u] = ++cnt;

        if (heavy[u])
            build(heavy[u]);
        for (int v : edge[u])
            if (v != par[u] && v != heavy[u])
                nChain++,
                build(v);
    }

    int getPoint(int a, int b){
        int res = 0;
        while (chain[a] != chain[b]){
            if(dep[head[chain[a]]] < dep[head[chain[b]]])
                swap(a, b);
            maximize(res, it.get(1, 1, num, pos[head[chain[a]]], pos[a]));
            a = par[head[chain[a]]];
        }
        if(dep[a] > dep[b])
            swap(a, b);
        return max(res, it.get(1, 1, num, pos[a], pos[b]));;
    }

    int getRange(int a, int b){
        int res = 0;
        while (1){
            if (chain[a] == chain[b]){
                res += it.get(1, 1, num, pos[a], pos[b]);
                break;
            }
            res += it.get(1, 1, num, pos[head[chain[b]]], pos[b]);
            b = par[head[chain[b]]];
        }
        return res;
    }

    void update(int a, int b){
        while (chain[a] != chain[b]){
            if(dep[head[chain[a]]] < dep[head[chain[b]]])
                swap(a, b);
            it.update(1, 1, num, pos[head[chain[a]]], pos[a]);
            a = par[head[chain[a]]];
        }
        if(dep[a] > dep[b])
            swap(a, b);
        it.update(1, 1, num, pos[a], pos[b]);
    }

    int lca(int u, int v) {
        while (in[u] != in[v]){
            if (dep[head[in[u]]] > dep[head[in[v]]])
                u = par[head[in[u]]];
            else
                v = par[head[in[v]]];
        }
        return dep[u] > dep[v] ? v : u;
    }

    void dfs(int u){
        sz[u] = 1;
        for (int v : edge[u])
            if (v != par[u]){
                par[v] = u;
                dep[v] = dep[u] + 1;
                dfs(v);
                sz[u] += sz[v];
                if (sz[v] > sz[heavy[u]])
                    heavy[u] = v;
            }
    }
} hld;