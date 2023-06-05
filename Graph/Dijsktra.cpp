
struct Edge{
    int v, cost;
};
int numNode, numEdge;
int check[MAX];
ll dis[MAX];
vector<Edge> edge[MAX];
bool visited[MAX];

struct Node {
    int u;
    ll uDist;
};

struct cmp {
    bool operator() (Node a, Node b){
        return a.uDist > b.uDist;
    }
};

void dijkstra(int u){
    FOR (i, 1, numNode)
        dis[i] = INF;
    dis[u] = 0;
    priority_queue<Node, vector<Node>, cmp> q;
    q.push({u, dis[u]});
    while (!q.empty()){
        auto x = q.top(); q.pop();
        int u = x.u;
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto edgeV : edge[u]){
            int v = edgeV.v;
            ll cost = edgeV.cost;
            if (dis[u] + cost < dis[u]){
                dis[v] = dis[u] + cost;
                q.push({v, dis[v]});
            }
        }
    }
}