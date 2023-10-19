struct Line {
    ll a, b;

    Line() {
        a = 0; b = INF;
    }

    Line(ll _a, ll _b){
        a = _a; b = _b;
    }

    ll ord(ll x){
        return a * x + b;
    }
};

struct DynamicLiChaoTree {
    struct Node {
        Line L;
        Node *l, *r;

        Node() {
            l = r = NULL;
        }
    };
    
    Node *root = new Node();

    void add(Node *it, int left, int right, Line L){
        if (left == right){
            if (it -> L.ord(left) > L.ord(left))
                it -> L = L;
            return;
        }
        int mid = (left + right) >> 1;
        if (it -> L.a > L.a)
            swap(it -> L, L);
        if (it -> L.ord(mid) > L.ord(mid)){
            swap(it -> L, L);
            if (!it -> r){
                it -> r = new Node();
                it -> r -> L = L;
                return;
            }
            add(it -> r, mid + 1, right, L);
        }else{
            if (!it -> l){
                it -> l = new Node();
                it -> l -> L = L;
                return;
            }
            add(it -> l, left, mid, L);
        }
    }

    ll get(Node *it, int left, int right, int x){
        if (!it)
            return INF;
        if (left == right){
            return it -> L.ord(x);
        }
        int mid = (left + right) >> 1;
        if (x <= mid){
            return min(it -> L.ord(x), get(it -> l, left, mid, x));
        }
        return min(it -> L.ord(x), get(it -> r, mid + 1, right, x));
    }

    void add(ll a, ll b){
        Line L = Line(a, b);
        add(root, -MAX, MAX, L);
    }

    ll get(int x){
        return get(root, -MAX, MAX, x);
    }
} lichao[MAX + 5];