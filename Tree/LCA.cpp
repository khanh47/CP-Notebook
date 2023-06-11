
int dep[MAX], up[MAX][LG];

void dfs(int u){
    for (int v : edge[u]){
        if (v == par[u][0])
            continue;

        dep[v] = dep[u] + 1;
        up[v][0] = u;

        for (int i = 1; MASK(i) <= numNode; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        dfs(v);
    }
}

int lca(int u, int v){
    if (dep[u] < dep[v])
        swap(u, v);
    int dis = dep[u] - dep[v];
    for (int i = 0; MASK(i) <= dis; i++)
        if (BIT(dis, i))
            u = up[u][i];

    if (u == v)
        return u;

    int lg = __lg(dep[u]);
    FOD (i, lg, 0)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}