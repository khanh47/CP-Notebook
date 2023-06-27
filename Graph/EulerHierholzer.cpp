int numNode, numEdge;
stack<int> st;
vector<pii> edge[MAX], ec;
int in[MAX];
bool used[MAX];
 
list<int> euler(int u){
    list<int> res;
    res.eb(u);
    while (edge[u].size()){
        auto[v, id] = edge[u].back();
        edge[u].pop_back();
        if (used[id])
            continue;
        used[id] = 1;
        u = v;
        res.eb(u);
    }
    for (auto it = ++res.begin(); it != res.end(); it++){
        auto t = euler(*it);
        t.pop_back();
        res.splice(it, t);
    }
    return res;
}
 
bool check(){
    FOR (i, 1, numNode)
        if (edge[i].size() & 1)
            return false;
    return true;
}
 
void solve(){
    if (!check()){
        printf("IMPOSSIBLE");
        return;
    }
    list<int> ec = euler(1);
    if (ec.size() <= numEdge){
        printf("IMPOSSIBLE");
        return;
    }
    for (int i : ec)
        printf("%d ", i);
}