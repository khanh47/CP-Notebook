const ll INF = 1e18 + 7;
const int MAX = 1e6;

struct Line {
    ll a, b;

    Line() {
        a = 0;
        b = INF;
    }

    Line(ll _a, ll _b){
        a = _a; b = _b;
    }

    ll ord(ll x){
        return a * x + b;
    }
};

struct LCT {
    Line tree[MAX * 4 + 7];

    void add(Line newLine){
        int id = 1, left = 0, right = MAX;
        while (1){
            if (left == right){
                if (tree[id].ord(left) > newLine.ord(left))
                    tree[id] = newLine;
                return;
            }
            int mid = (left + right) >> 1;
            if (tree[id].a > newLine.a)
                swap(tree[id], newLine);
            if (tree[id].ord(mid) > newLine.ord(mid))
                swap(tree[id], newLine),
                id = id << 1 | 1,
                left = mid + 1;
            else
                id <<= 1,
                right = mid;
        }
    }

    ll get(ll x){
        int id = 1, left = 0, right = MAX;
        ll res = INF;
        while (1){
            minimize(res, tree[id].ord(x));
            if (left == right)
                break;
            int mid = (left + right) >> 1;
            id <<= 1;
            if (x <= mid)
                right = mid;
            else
                id++,
                left = mid + 1;
        }
        return res;
    }
} lct;