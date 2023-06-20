struct MaxFlow {
    int src, sink;
    vector<int> edge[MAX];
    int capacity[MAX][MAX], flow[MAX][MAX], trace[MAX];
    bool vis[MAX];

    void add(int u, int v, int c){
        if (c != capacity[u][v] && capacity[u][v])
            return;
        edge[u].eb(v);
        edge[v].eb(u);
        capacity[u][v] = c;
    }

    bool bfs(){
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(src);
        while (q.size()){
            int u = q.front(); q.pop();
            for (int v : edge[u])
                if (!vis[v] && capacity[u][v] > flow[u][v]){
                    vis[v] = 1;
                    trace[v] = u;
                    if (v == sink)
                        return 1;
                    q.push(v);
                }
        }
        return 0;
    }

    void increase(){
        int mn = INF, pre;
        for (int u = sink; u != src; u = pre){
            pre = trace[u];
            minimize(mn, capacity[pre][u] - flow[pre][u]);
        }
        for (int u = sink; u != src; u = pre){
            pre = trace[u];
            flow[pre][u] += mn;
            flow[u][pre] -= mn;
        }
    }

    ll maxFlow(int _src, int _sink){
        src = _src; sink = _sink;
        while (bfs())
            increase();
        ll res = 0;
        for (int v : edge[src])
            res += flow[src][v];
        return res;
    }
} flow;