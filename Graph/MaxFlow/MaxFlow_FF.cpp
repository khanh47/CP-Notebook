const int MAX = 1e3 + 5;
const int INF = 1e9 + 7;

int numNode, numEdge, src, sink;
vector<int> edge[MAX];
int capacity[MAX][MAX], flow[MAX][MAX], trace[MAX], minC[MAX];
bool vis[MAX];

void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (q.size()){
        int u = q.front(); q.pop();
        for (int v : edge[u])
            if (!vis[v] && capacity[u][v] > flow[u][v]){
                vis[v] = true;
                trace[v] = u;
                if (v == sink)
                    return;
                q.push(v);
            }
    }
}

bool pfs(int u){
    memset(vis, 0, sizeof(vis));
    memset(minC, 0, sizeof(minC));
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({u, INF});
    while (heap.size()){
        auto[u, cur] = heap.top(); heap.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int v : edge[u])
            if (!vis[v] && min(cur, capacity[u][v] - flow[u][v]) > minC[v]){
                minC[v] = capacity[u][v] - flow[u][v];
                trace[v] = u;
                if (v == sink)
                    return 1;
                heap.push({v, minC[v]});
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

void solve(){
    while (pfs(src))
        increase();
    int res = 0;
    for (int v : edge[src])
        res += flow[src][v];
    cout << res;
}

void read(){
    cin >> numNode >> numEdge >> src >> sink;
    FOR (i, 1, numEdge){
        static int u, v;
        cin >> u >> v >> capacity[u][v];
        edge[u].eb(v);
        edge[v].eb(u);
    }
}

int main(){
    int test = 1;
//    cin >> test;
    while (test--)
        read(),
        solve();
}