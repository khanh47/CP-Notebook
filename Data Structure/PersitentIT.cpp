const int N = 2e5 + 7;
const int MAX = 4e6 + 7; // N * (4 + LOG2(N))
const ll INF = 1e12 + 7;
 
int num, query;
int val[N];

struct IT {
    struct Node {
        int left, right;
        ll val;
 
        Node(int _left = 0, int _right = 0, ll _val = 0){
            left = _left; right = _right; val = _val;
        }
    } tree[MAX];
    
    int node, ver, root[N];
 
    void update(int id){
        tree[id].val = tree[tree[id].left].val + tree[tree[id].right].val;
    }

    void build(int id, int left, int right){
        maximize(node, id);
        if (left == right){
            tree[id].val = val[left];
            return;
        }
        int mid = (left + right) >> 1;
        tree[id].left = id << 1; tree[id].right = id << 1 | 1;
        build(id << 1, left, mid);
        build(id << 1 | 1, mid + 1, right);
        update(id);
    }
 
    void update(int cur, int pre, int left, int right, int pos, int val){
        if (left == right){
            tree[cur].val = val;
            return;
        }
        int mid = (left + right) >> 1;
        if (pos <= mid){
            tree[cur].left = ++node;
            tree[cur].right = tree[pre].right;
            update(tree[cur].left, tree[pre].left, left, mid, pos, val);
        }else{
            tree[cur].left = tree[pre].left;
            tree[cur].right = ++node;
            update(tree[cur].right, tree[pre].right, mid + 1, right, pos, val);
        }
        tree[cur].val = tree[tree[cur].left].val + tree[tree[cur].right].val;
    }
 
    void update(int ver, int pos, int val){
        int cur = ++node;
        update(cur, root[ver], 1, num, pos, val);
        root[ver] = cur;
    }
 
    ll get(int id, int left, int right, int l, int r){
        if (r < left || right < l)
            return 0;
        if (l <= left && right <= r)
            return tree[id].val;
        int mid = (left + right) >> 1;
        return get(tree[id].left, left, mid, l, r) +
        get(tree[id].right, mid + 1, right, l, r);
    }
 
    ll get(int ver, int l, int r){
        return get(root[ver], 1, num, l, r);
    }
 
    void copy(int pre){
        root[++ver] = root[pre];
    }
} it;
 
void solve(){
    while (query--){
        static int type, ver, left, right;
        cin >> type >> ver;
        if (type == 1){
            cin >> left >> right;
            it.update(ver, left, right);
        }
        if (type == 2){
            cin >> left >> right;
            cout << it.get(ver, left, right) << endl;
        }
        if (type == 3)
            it.copy(ver);
    }
}
 
void read(){
    cin >> num >> query;
    FOR (i, 1, num)
        cin >> val[i];
    it.build(1, 1, num);
    it.root[1] = 1;
    it.ver = 1;
}