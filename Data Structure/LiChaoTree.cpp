struct Line {
    ll a, b;

    Line() {
        a = 0; b = INF;
    }

    Line (ll _a, ll _b){
        a = _a; b = _b;
    }

    ll ord(ll x){
        return a * x + b;
    }
};

struct LCT {
    Line tree[MAXX << 2];

    void update(int id, int left, int right, Line newLine){
        if (left == right){
            if (newLine.ord(left) < tree[id].ord(left))
                tree[id] = newLine;
            return;
        }
        if (tree[id].a > newLine.a)
            swap(tree[id], newLine);
        int mid = (left + right) >> 1;
        if (tree[id].ord(mid) > newLine.ord(mid)){
            swap(tree[id], newLine);
            update(id << 1 | 1, mid + 1, right, newLine);
        }else
            update(id << 1, left, mid, newLine);
    }

    ll get(int id, int left, int right, int x){
        if (left == right)
            return tree[id].ord(x);
        int mid = (left + right) >> 1;
        if (x <= mid)
            return min(tree[id].ord(x), get(id << 1, left, mid, x));
        return min(tree[id].ord(x), get(id << 1 | 1, mid + 1, right, x));
    }
} lct;