// test: https://cses.fi/problemset/task/1137
// nodes v that have in[v] in range [in[u], out[u]] are subtree of u

void dfs(int u, int pre){
    in[u] = ++cnt;
    it.update(1, 1, num, cnt, val[u]);
    for (int v : edge[u]){
        if (v == pre)
            continue;
        dfs(v, u);
    }
    out[u] = cnt;
}
 
void solve(){
    dfs(1, -1);
    while (query--){
        static int type, u, val;
        cin >> type >> u;
        if (type & 1){
            cin >> val;
            it.update(1, 1, num, in[u], val);
        }else
            cout << it.get(1, 1, num, in[u], out[u]) << endl;
    }
}