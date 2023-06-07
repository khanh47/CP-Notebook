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
    // nodes[x] contains all relevant y coordinates
    vector<vector<int>> nodes, bit;
    int sz;

    void init(int n){
        sz = n;
        nodes.resize(sz + 5);
        bit.resize(sz + 5);
    }

    void initNodes(){
        for (int i = 1; i <= sz; i++){
            nodes[i].push_back(INF);
            sort(nodes[i].begin(), nodes[i].end());
            nodes[i].erase(unique(nodes[i].begin(), nodes[i].end()), nodes[i].end());
            bit[i].resize(nodes[i].size() + 1);
        }
    }

    void fakeUpdate(int x, int y){
        for (; x <= sz; x += x & (-x))
            nodes[x].push_back(y);
    }

    void fakeGet(int x, int y){
        for (; x > 0; x -= x & (-x))
            nodes[x].push_back(y);
    }

    // point (u, v) += val
    void update(int u, int v, int val){
        for (int x = u; x <= sz; x += x & (-x))
            for (int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin() + 1; y <= (int) nodes[x].size(); y += y & (-y))
                bit[x][y] += val;
    }

    // Get sum of point in rectangle with corners at (1, 1) and (u, v)
    int get(int u, int v){
        int res = 0;
        for (int x = u; x; x -= x & (-x))
            for (int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y; y -= y & (-y))
                res += bit[x][y];
        return res;
    }
} tree;