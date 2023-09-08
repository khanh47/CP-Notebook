// Tested:
// - (binary search) https://atcoder.jp/contests/practice2/tasks/practice2_j
// - https://oj.vnoi.info/problem/gss
// - https://oj.vnoi.info/problem/nklineup
// - (max_right & min_left for delete position queries) https://oj.vnoi.info/problem/segtree_itstr
// - https://judge.yosupo.jp/problem/point_add_range_sum
// - https://judge.yosupo.jp/problem/point_set_range_composite

const int MAX = 1e5 + 7;

struct IntervalTree {
    struct node {
        int code, num;
    };

    node tree[MAX << 2];
    int pw[MAX], lazy[MAX << 2];

    node Merge(node a, node b){
        node res;
        res.num = a.num + b.num;
        res.code = add(muti(a.code, pw[b.num]), b.code);
        return res;
    }

    void build(int id, int left, int right){
        if (left == right){
            tree[id] = {val[left], 1};
            return;
        }

        int mid = (left + right) >> 1;
        build(id << 1, left, mid);
        build(id << 1 | 1, mid + 1, right);

        tree[id] = Merge(tree[id << 1], tree[id << 1 | 1]);
    }

    void down(int id){
        if (lazy[id] < 0)
            return;
        int val = lazy[id];
        lazy[id] = -1;
        tree[id << 1].code = (pw[tree[id << 1].num] - 1) * val;
        tree[id << 1 | 1].code = (pw[tree[id << 1 | 1].num] - 1) * val;
        lazy[id << 1] = lazy[id << 1 | 1] = val;
    }

    void update(int id, int left, int right, int u, int v, int val){
        if (v < left || right < u)
            return;
        if (u <= left && right <= v){
            tree[id].code = (pw[tree[id].num] - 1) * val;
            lazy[id] = val;
            return;
        }

        down(id);
        int mid = (left + right) >> 1;
        update(id << 1, left, mid, u, v, val);
        update(id << 1 | 1, mid + 1, right, u, v, val);

        tree[id] = Merge(tree[id << 1], tree[id << 1 | 1]);
    }

    node get(int id, int left, int right, int u, int v){
        if (v < left || right < u)
            return {0, 0};
        if (u <= left && right <= v)
            return tree[id];

        down(id);
        int mid = (left + right) >> 1;
        node get1 = get(id << 1, left, mid, u, v);
        node get2 = get(id << 1 | 1, mid + 1, right, u, v);

        return Merge(get1, get2);
    }

    int Find(int id, int left, int right, int val){
        if (left == right)
            return left;
        down(id);
        int mid = (left + right) >> 1;
        if (tree[id << 1].code >= val)
            return Find(id << 1, left, mid, val);
        return Find(id << 1 | 1, mid + 1, right, val);
    }
} it;