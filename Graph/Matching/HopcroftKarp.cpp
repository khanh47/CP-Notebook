// usage: 
// 1. match.addEdge(u, v)
// 2. match.maxMatching(numX, numY)
// 3. match.trace()

struct MaxMatching {
    int numX, numY;
    int matchX[MAX], matchY[MAX], dis[MAX];
    vector<int> edge[MAX];

    void addEdge(int u, int v){
        edge[u].eb(v);
    }

    bool bfs(){
        memset(dis, 0, sizeof(dis));
        dis[0] = INF;
        queue<int> q;
        FOR (i, 1, numX)
            if (!matchX[i])
                dis[i] = 0,
                q.push(i);
            else
                dis[i] = INF;
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

    int maxMatching(int _numX, int _numY){
        numX = _numX; numY = _numY;
        int res = 0;
        while (bfs())
            FOR (i, 1, numX)
                if (!matchX[i] && dfs(i))
                    res++;
        return res;
    }

    void trace(){
        FOR (i, 1, numX)
            if (matchX[i])
                cout << i << ' ' << matchX[i] << endl;
    }
} match;