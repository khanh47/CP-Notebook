struct BellmanFord{
    int numNode, numEdge, start = -1;
    int trace[MAX];
    ll dis[MAX];
    vector<tuple<int, int, int>> edge;

    void addEdge(int u, int v, int cost){
        edge.pb({u, v, cost});
    }
    
    int bellmanFord(int src, int _numNode, int _numEdge){
        numNode = _numNode; numEdge = _numEdge;
        FOR (i, 1, numNode)
            dis[i] = INF;
        dis[src] = 0;
        FOR (i, 2, numNode)
            for (auto[u, v, cost] : edge)
                if (minimize(dis[v], dis[u] + cost))
                    trace[v] = u;
        FOR (i, 1, numNode)
           for (auto[u, v, cost] : edge)
                if (minimize(dis[v], dis[u] + cost)){
                    dis[v] = -INF;
                    trace[v] = u;
                    start = v;
                }
    }
    
    ll getDis(int u){
        return dis[u];
    }

    void negCycle(){
        if (start < 0){
            cout << "NO";
            return;
        }
        int u = start;
        FOR (i, 1, numNode)
            u = trace[u];
        vector<int> res;
        for (int v = trace[u]; v != u; v = trace[v])
            res.eb(v);
        res.eb(u);
        reverse(ALL(res));
        res.eb(u);
        cout << "YES\n";
        for (int i : res)
            cout << i << ' ';
    }
} bf;