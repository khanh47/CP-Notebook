// https://codeforces.com/gym/487590/problem/B
// given a tree N nodes, Q queries
// each query:
// type 1: check if (u, v) in a component
// type 2: delete edge (u, v)

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fi first
#define se second
#define eb emplace_back
#define pii pair<int, int>

using namespace std;

const int MAX = 1e6 + 2;

int numNode, numEdge, query, cnt;
vector<pii> adj[MAX];
pii edge[MAX];
bool del[MAX];
int lab[MAX], vis[MAX], pos[2], node[2], sz[2], past[MAX][2];
queue<int> q[2];

void init(int numNode, vector<pii> E){
    FOR (i, 0, E.size() - 1){
        auto [u, v] = E[i];
        if (u > v)
            swap(u, v);
        edge[++numEdge] = pii(u, v);
    }
    sort(edge + 1, edge + 1 + numEdge);
    FOR (i, 1, numEdge){
        auto [u, v] = edge[i];
        adj[u].eb(pii(v, i));
        adj[v].eb(pii(u, i));
    }
    return;
}

bool question(int u, int v){
    return lab[u] == lab[v];
}

void Del(int u, int i){
    swap(adj[u][i], adj[u].back());
    adj[u].pop_back();
}

void close(int u, int v){
    // init
    FOR (i, 0, 1)
        while (q[i].size())
            q[i].pop();
    q[0].push(u); q[1].push(v);
    sz[0] = sz[1] = 0;
    past[++sz[0]][0] = u;
    past[++sz[1]][1] = v;
    pos[0] = pos[1] = 0;
    vis[u] = vis[v] = ++cnt;

    // delete
    if (u > v)
        swap(u, v);
    int idx = lower_bound(edge + 1, edge + 1 + numEdge, pii(u, v)) - edge;
    del[idx] = 1;

    // bfs small size
    while (1){
        int u[2];
        FOR (i, 0, 1)
            u[i] = q[i].front();

        // add each node from 2 sides
        for (; pos[0] < adj[u[0]].size() && pos[1] < adj[u[1]].size(); pos[0]++, pos[1]++){
            // find 2 adjacent nodes of 2 nodes from 2 sides
            node[0] = node[1] = 0;
            FOR (i, 0, 1){
                auto [v, id] = adj[u[i]][pos[i]];

                while (del[id]){
                    Del(u[i], pos[i]);
                    if (pos[i] >= adj[u[i]].size())
                        break;
                    v = adj[u[i]][pos[i]].fi;
                    id = adj[u[i]][pos[i]].se;
                }

                if (pos[i] >= adj[u[i]].size())
                    continue;

                if (vis[v] != cnt)
                    node[i] = v;
            }
            // check if 2 current nodes from 2 sides still has adjacent node
            if (node[0] && node[1]){
                FOR (i, 0, 1)
                    past[++sz[i]][i] = node[i],
                    vis[node[i]] = cnt,
                    q[i].push(node[i]);
            }else{
                FOR (i, 0, 1)
                    if (node[i])
                        pos[i]--;
            }
        }

        // check if no adjacent node
        FOR (i, 0, 1){
            if (pos[i] >= adj[u[i]].size()){
                q[i].pop();
                pos[i] = 0;
            }
            // check which side is smaller
            if (q[i].empty()){
                FOR (j, 1, sz[i])
                    lab[past[j][i]] = cnt;
                return;
            }
        }
    }
}