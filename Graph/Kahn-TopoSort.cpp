
int in[MAX];
vector<int> topo, g[MAX];
void kahn(){
    queue<int> q;
    FOR (i, 1, n)
        if (!in[i])
            q.push(i);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : g[u]){
            in[v]--;
            if (!in[v])
                q.push(v);
        }
    }
}