
int numNode, numEdge;
vector<int> edge[MAX];
int low[MAX], num[MAX];
stack<int> st;
bool deleted[MAX];
int cnt = 0, scc = 0;

void dfs(int u){
    num[u] = low[u] = ++cnt;
    st.push(u);
    for (int v : edge[u]){
        if (deleted[v])
            continue;
        if (num[v]){
            minimize(low[u], num[v]);
            continue;
        }
        dfs(v);
        minimize(low[u], low[v]);
    }
    if (low[u] == num[u]){
        scc++;
        int v = u + 1;
        while (u != v){
            v = st.top(); st.pop();
            deleted[v] = true;
        }
    }
}
