// test:
// https://oj.vnoi.info/problem/fc077_grcolor2
// https://oj.vnoi.info/problem/fct018_grcolor2 
// in[a] = timeDfs of node a by euler tour

#define eb emplace_back
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,b,a) for (int i = (b), _a = (a); i >= _a; i--)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))

const int MAX = 1e5 + 7;
const int LG = 20;

int num;
vector<int> adj[MAX];
vector<int> edge[MAX], adj[MAX];
int par[MAX][LG], dep[MAX], in[MAX], out[MAX], cnt = 0;

void build(int u, int pre){
    in[u] = ++cnt;
    for (int v : edge[u]){
        if (v == pre)
            continue;
        dep[v] = dep[u] + 1;
        par[v][0] = u;
        for (int i = 1; MASK(i) <= dep[v]; i++)
            par[v][i] = par[par[v][i - 1]][i - 1];
        build(v, u);
    }
    out[u] = cnt;
}

int lca(int u, int v){
    if (dep[u] < dep[v])
        swap(u, v);
    int dis = dep[u] - dep[v];
    for (int i = 0; MASK(i) <= dis; i++)
        if (BIT(dis, i))
            u = par[u][i];
    if (u == v)
        return u;
    int lg = __lg(dep[u]);
    FOD (i, lg, 0)
        if (par[u][i] != par[v][i])
            u = par[u][i],
            v = par[v][i];
    return par[u][0];
}

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