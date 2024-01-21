// 2D Fenwick
// Note:
// - For faster implementation which also supports Rectagle ADD, see:
//   https://hitonanode.github.io/cplib-cpp/data_structure/rectangle_add_rectangle_sum.hpp
//
// If cannot use the struct directly, do:
// 1. init
// 2. fakeUpdate / fakeGet
// 3. initNodes
// 4. get
//
// Tested:
// - https://judge.yosupo.jp/problem/rectangle_sum
// - https://judge.yosupo.jp/problem/point_add_rectangle_sum
// - https://oj.vnoi.info/problem/kl11b
// - https://oj.vnoi.info/problem/lis2vn

struct BIT2D {
    vector<int> tree[MAX], nodes[MAX];

    void fakeUpdate(int x, int y){
        for (int a = x; a <= num; a += a & (-a))
            for (int b = y; b <= num; b += b & (-b))
                nodes[a].eb(b);
    }

    void fakeGet(int x, int y){
        if (!x || !y) return;
        for (int a = x; a; a -= a & (-a))
            for (int b = y; b; b -= b & (-b))
                nodes[a].eb(b);
    }

    void fakeGet(int x, int y, int xx, int yy){
        fakeGet(xx, yy); fakeGet(xx, y - 1); fakeGet(x - 1, yy); fakeGet(x - 1, y - 1);
    }

    void build(){
        FOR (i, 1, num){
            if (nodes[i].empty()) continue;
            sort(ALL(nodes[i]));
            nodes[i].resize(unique(ALL(nodes[i])) - nodes[i].begin());
            tree[i].resize(nodes[i].size());
        }
    }

    int Find(int a, int b){
        return lower_bound(ALL(nodes[a]), b) - nodes[a].begin() + 1;
    }

    void update(int x, int y, int val){
        for (int a = x; a <= num; a += a & (-a))
            for (int b = Find(a, y); b <= nodes[a].size(); b += b & (-b))
                tree[a][b - 1] += val;
    }

    int get(int x, int y){
        if (!x || !y) return 0;
        int res = 0;
        for (int a = x; a; a -= a & (-a))
            for (int b = Find(a, y); b; b -= b & (-b))
                res += tree[a][b - 1];
         return res;
     }

     int get(int x, int y, int xx, int yy){
         return get(xx, yy) - get(xx, y - 1) - get(x - 1, yy) + get(x - 1, y - 1);
    }
} bit;