// tested: https://oj.vnoi.info/problem/fc148_treecount
// nodes v that have out[v] in range (in[u], out[u]] are subtree of u

void dfs(int u, int pre){
    in[u] = cnt;
    for (int v : edge[u])
        if (v != pre)
            dfs(v, u);
    out[u] = ++cnt;
}

void solve(){
    dfs(1, -1);
    sort(val + 1, val + 1 + num, greater<pii>());
    FOR (i, 1, num){
        auto[cost, u] = val[i];
        
        res[u] = tree.get(out[u]) - bit.get(in[u]);
        bit.update(out[u]);
//        cout << u << ' ' << in[u] << ' ' << out[u] << endl;
    }
}