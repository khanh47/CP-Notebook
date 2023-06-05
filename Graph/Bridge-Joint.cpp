
int num[10004], low[10004], joint[10004];
vector<int> g[10004];
int timeDfs, c;

void dfs(int u, int pre){
    num[u] = low[u] = ++timeDfs;
    int child = 0;
    for(int v : g[u]){
        if (v == pre)
            continue;
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            child++;
            if (low[v] == num[v])
                c++;
            if (u == pre){
                if (child > 1)
                    joint[u] = 1;
            }else if (low[v] >= num[u])
                joint[u] = 1;
        }else
            low[u] = min(low[u], num[v]);
    }
}