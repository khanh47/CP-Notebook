// Complexity: O(E.V)
int numX, numY, numEdge;
int matchX[MAX], matchY[MAX], trace[MAX];
vector<int> edge[MAX];

int bfs(){
    FOR (i, 1, numY)
        trace[i] = 0;
    queue<int> q;
    FOR (i, 1, numX)
        if (!matchX[i])
            q.push(i);
    while (q.size()){
        int u = q.front(); q.pop();
        for (int v : edge[u])
            if (!trace[v]){
                trace[v] = u;
                if (!matchY[v])
                    return v;
                q.push(matchY[v]);
            }
    }
    return 0;
}

void enlarge(int y){
    int x, next;
    for (; y; y = next){
        x = trace[y];
        next = matchX[x];
        matchX[x] = y;
        matchY[y] = x;
    }
}

void maxMatching(){
    int i;
    while (i = bfs())
        enlarge(i);
    int res = 0;
    FOR (i, 1, numX)
        res += (matchX[i] > 0);
    return res;
}