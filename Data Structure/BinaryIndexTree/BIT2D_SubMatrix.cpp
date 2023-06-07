
ll fen[4][MAX][MAX];

struct RangeFenwick2D {
    int n, m;

    void build(int n, int m){
        this->n = n, this->m = m;
    }

    void upd(int x, int y, ll val){
        assert(0 < x && 0 < y);
        for (int xx = x; xx <= n; xx += xx & -xx){
            for (int yy = y; yy <= m; yy += yy & -yy){
                fen[0][xx][yy] += val;
                fen[1][xx][yy] += x * val;
                fen[2][xx][yy] += y * val;
                fen[3][xx][yy] += x * y * val;
            }
        }
    }

    void upd(int x, int y, int z, int t, ll val){
        upd(x, y, val);
        upd(x, t + 1, -val);
        upd(z + 1, y, -val);
        upd(z + 1, t + 1, val);
    }

    ll query(int x, int y){
        assert(x <= n && y <= m);
        ll res = 0;
        for (int xx = x; xx > 0; xx -= xx & -xx){
            for (int yy = y; yy > 0; yy -= yy & -yy){
                res += (x + 1) * (y + 1) * fen[0][xx][yy];
                res -= (y + 1) * fen[1][xx][yy];
                res -= (x + 1) * fen[2][xx][yy];
                res += fen[3][xx][yy];
            }
        }
        return res;
    }

    ll query(int x, int y, int z, int t){
        return query(z, t) - query(x - 1, t) - query(z, y - 1) + query(x - 1, y - 1);
    }
} tree;