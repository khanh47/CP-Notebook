const int MAX = 1e3 + 5;
const int INF = 1e9 + 7;

int numNode, numEdge, src, sink;
vector<int> edge[MAX];
int capacity[MAX][MAX], flow[MAX][MAX], trace[MAX];
bool vis[MAX], S[MAX];

bool bfs(int u){
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(u);
    while (q.size()){
        int u = q.front(); q.pop();
        for (int v : edge[u])
            if (!vis[v] && capacity[u][v] > flow[u][v]){
                trace[v] = u;
                if (v == sink)
                    return 1;
                vis[v] = 1;
                q.push(v);
            }
    }
    return 0;
}

void increase(){
    int mn = INF;
    int u = sink;
    while (u != src){
        int pre = trace[u];
        minimize(mn, capacity[pre][u] - flow[pre][u]);
        u = pre;
    }
    u = sink;
    while (u != src){
        int pre = trace[u];
        flow[pre][u] += mn;
        flow[u][pre] -= mn;
        u = pre;
    }
}

int maxFlow(){
    while (bfs(src))
        increase();
    int res = 0;
    for (int v : edge[src])
        res += flow[src][v];
    return res;
}

vector<int> minCut(){
    vector<int> V;
    vector<pair<int, int>> res;
    S[src] = 1;
    queue<int> q;
    q.push(src);
    while (q.size()){
        int u = q.front(); q.pop();
        for (int v : edge[u])
            if (!S[v] && capacity[u][v] > flow[u][v])
                S[v] = 1,
                V.eb(v),
                q.push(v);
    }
    for (int u : V)
        for (int v : edge[u])
            if (!S[v])
                res.pb({u, v});
    return res;
}