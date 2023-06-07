
int bit[MAX][MAX];

struct RangeFenwick2D {
    int n, m;

    void build(int n, int m){
        this->n = n, this->m = m;
    }

    void update(int x, int y, ll val){
        assert(0 < x && 0 < y);
        for (int xx = x; xx <= n; xx += xx & -xx)
            for (int yy = y; yy <= m; yy += yy & -yy)
                bit[xx][yy] += val;
    }

    ll get(int x, int y){
        assert(x <= n && y <= m);
        ll res = 0;
        for (int xx = x; xx > 0; xx -= xx & -xx)
            for (int yy = y; yy > 0; yy -= yy & -yy)
                res += bit[xx][yy];
        return res;
    }
} tree;