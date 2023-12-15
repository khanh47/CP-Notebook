// test:
// use when there are Q queries and each query has N node of tree and sum of N in Q queries <= 1e5
// https://oj.vnoi.info/problem/fc077_grcolor2
// https://oj.vnoi.info/problem/fct018_grcolor2 

bool cmp(int a, int b){
    return in[a] < in[b];
}

void decompose(){
    static int num;
    vector<int> V;
    cin >> num;
    FOR (i, 1, num){
        static int u;
        cin >> u;
        V.eb(u);
    }
    sort(ALL(V), cmp);
    FOR (i, 1, num - 1)
        V.eb(lca(V[i], V[i - 1]));
    V.eb(1);
    sort(ALL(V), cmp);
    V.resize(unique(ALL(V)) - V.begin());
    stack<int> st;
    for (int u : V){
        if (st.empty()){
            st.push(u);
            continue;
        }
        while (out[st.top()] < in[u])
            st.pop();
        adj[st.top()].eb(u);
        st.push(u);
    }
}