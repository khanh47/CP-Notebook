void dfs(int u, int pre, bool hold){
    for (int v : edge[u])
        if (v != pre && v != heavy[u])
            dfs(v, u, 0);
    if (heavy[u])
        dfs(heavy[u], u, 1);
    for (int v : edge[u])
        if (v != pre && v != heavy[u])
            FOR (i, in[v], out[v])
                update(id[i], 1);
    update(u, 1);
    res[u] = query();
    if (!hold)
        FOR (i, in[u], out[u])
            update(id[i], -1);
}