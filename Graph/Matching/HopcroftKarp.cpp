const int MAX = 5e4 + 5;
const int INF = 1e9 + 7;

int numX, numY, numEdge;
int matchX[MAX], matchY[MAX], dis[MAX];
vector<int> edge[MAX];

bool bfs(){
    queue<int> q;
    FOR (i, 1, numX){
        if (!matchX[i])
            dis[i] = 0,
            q.push(i);
        else
            dis[i] = INF;
    }
    dis[0] = INF;
    while (q.size()){
        int u = q.front(); q.pop();
        if (dis[u] == dis[0])
            continue;
        for (int v : edge[u])
            if (dis[matchY[v]] == INF)
                dis[matchY[v]] = dis[u] + 1,
                q.push(matchY[v]);
    }
    return dis[0] < INF;
}

bool dfs(int u){
    if (!u)
        return 1;
    for (int v : edge[u])
        if (dis[matchY[v]] == dis[u] + 1 && dfs(matchY[v])){
            matchX[u] = v;
            matchY[v] = u;
            return 1;
        }
    dis[u] = INF;
    return 0;
}

int maxMatching(){
    int res = 0;
    while (bfs())
        FOR (i, 1, numX)
            if (!matchX[i] && dfs(i))
                res++;
    return res;
}