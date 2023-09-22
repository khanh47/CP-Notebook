struct CD {
    vector<int> edge[MAX];
    int sz[MAX], par[MAX], res[MAX];
    unordered_map<int, int> dis[MAX];
    bool del[MAX];
 
    void addEdge(int u, int v){
        edge[u].eb(v);
        edge[v].eb(u);
    }
 
    void init(){
        FOR (i, 1, num)
            res[i] = INF;
    }
 
    void dfs(int u, int pre){
        sz[u] = 1;
        for (int v : edge[u])
            if (!del[v] && v != pre)
                dfs(v, u),
                sz[u] += sz[v];
    }
 
    int centroid(int u, int pre, int n){
        for (int v : edge[u])
            if (!del[v] && v != pre && sz[v] > n)
                return centroid(v, u, n);
        return u;
    }
 
    void dfs2(int u, int pre, int dep, int root){
        dis[root][u] = dep;
        for (int v : edge[u])
            if (!del[v] && v != pre)
                dfs2(v, u, dep + 1, root);
    }
 
    void build(int u, int pre){
        dfs(u, -1);
        u = centroid(u, -1, sz[u] >> 1);
        dfs2(u, par[u] = pre, 0, u);
        del[u] = 1;
        for (int v : edge[u])
            if (!del[v])
                build(v, u);
    }
 
    void update(int u){
        for (int v = u; v; v = par[v])
            minimize(res[v], dis[v][u]);
    }
 
    int get(int u){
        int ans = INF;
        for (int v = u; v; v = par[v])
            minimize(ans, res[v] + dis[v][u]);
        return ans;
    }
} cd;