
int dep[MAX], par[MAX][LG];
void dfs(int u){
    visited[u] = true;
    for (auto edgeV : edge[u]){
        int v = edgeV.v, cost = edgeV.cost;
        if (visited[v])
            continue;

        dep[v] = dep[u] + 1;
        par[v][0] = u;

        for (int i = 1; MASK(i) <= numNode; i++)
            par[v][i] = par[par[v][i - 1]][i - 1];
        dfs(v);
    }
}

int lca(int u, int v){
    if (dep[u] < dep[v])
        swap(u, v);
    int dis = dep[u] - dep[v];
    for (int i = 0; MASK(i) <= dis; i++)
        if (BIT(dis, i))
            u = par[u][i];

    if (u == v)
        return u;

    int lg = __lg(dep[u]);
    FOD (i, lg, 0)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}