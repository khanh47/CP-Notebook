// usage: 
// 1. addEdge(u, posU, v, posV) (to add directed edge between u and v (if visit u then posU == 1 else posU == 0))
// 2. init(numNode)
// 3. build() (if build == 0 then there is no way to solve)
// 4. query(u) == 1 if u is in graph else query(u) == 2
// 
// tested: https://cses.fi/problemset/task/1684

struct TwoSat {
    int numNode;
    vector<vector<int>> edge, adj;
    vector<int> num, low, lab, opp, res, in;
    stack<int> st;
    int cnt, scc;

    void init(int _numNode){
        numNode = _numNode;
        cnt = scc = 0;
        edge.resize(numNode << 1 | 1);
        adj.resize(numNode << 1 | 1);
        num.resize(numNode << 1 | 1);
        low.resize(numNode << 1 | 1);
        opp.resize(numNode << 1 | 1);
        lab.resize(numNode << 1 | 1, 0);
        res.resize(numNode << 1 | 1, 0);
        in.resize(numNode << 1 | 1, 0);
    }

    int neg(int u){
        return (u > numNode ? u - numNode : u + numNode);
    }

    void addEdge(int u, bool posU, int v, bool posV){
        u = (posU ? u : neg(u));
        v = (posV ? v : neg(v));
        edge[neg(u)].eb(v); edge[neg(v)].eb(u);
    }

    void dfs(int u){
        num[u] = low[u] = ++cnt;
        st.push(u);
        for (int v : edge[u]){
            if (lab[v])
                continue;
            if (num[v]){
                minimize(low[u], num[v]);
                continue;
            }
            dfs(v);
            minimize(low[u], low[v]);
        }
        if (num[u] == low[u]){
            scc++;
            int v = 0;
            while (v != u){
                v = st.top(); st.pop();
                lab[v] = scc;
            }
        }
    }

    void link(){
        FOR (u, 1, numNode << 1)
            for (int v : edge[u])
                if (lab[u] != lab[v])
                    adj[lab[v]].eb(lab[u]),
                    in[lab[u]]++;
    }

    void topo(){
        queue<int> q;
        FOR (i, 1, scc)
            if (!in[i])
                q.push(i);
        while (q.size()){
            int u = q.front(); q.pop();
            if (!res[u])
                res[u] = 1,
                res[opp[u]] = 2;
            for (int v : adj[u]){
                in[v]--;
                if (!in[v])
                    q.push(v);
            }
        }
    }

    bool build(){
        FOR (i, 1, numNode << 1)
            if (!num[i])
                dfs(i);
        FOR (i, 1, numNode){
            if (lab[i] == lab[neg(i)])
                return 0;
            opp[lab[i]] = lab[neg(i)];
            opp[lab[neg(i)]] = lab[i];
        }
        link();
        topo();
        return 1;
    }

    int query(int u){
        return res[lab[u]];
    }
} sat;