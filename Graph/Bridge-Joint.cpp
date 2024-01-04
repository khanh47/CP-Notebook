int numNode, numEdge, cnt, bridge;
vector<int> edge[MAX];
bool art[MAX];
int num[MAX], low[MAX];

void dfs(int u, int pre){
    num[u] = low[u] = ++cnt;
    int child = 0;
    for (int v : edge[u]){
        if (v == pre)
            continue;
        if (num[v]){
            minimize(low[u], num[v]);
            continue;
        }
        dfs(v, u);
        child++;
        minimize(low[u], low[v]);
        if (pre < 0){
            if (child > 1)
                art[u] = 1;
        }else if (low[v] >= num[u])
            art[u] = 1;
        bridge += num[v] == low[v];
    }
}

void solve(){
    int joint = 0;
    FOR (i, 1, numNode){
        if (!num[i])
            dfs(i, -1);
        joint += art[i];
    }
    cout << joint << ' ' << bridge;
}