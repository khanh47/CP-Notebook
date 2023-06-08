#define MASK(i) (1LL << (i))

template<class X, class Y> bool maximize(X &x, Y y){ if (x < y){ x = y; return true; } return false; }
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y){ x = y; return true; } return false; }

const int MAX = 1e5 + 7;
const int LG = 20;

struct SparseTable {
    int table[MAX][22], n;

    void build(){
        FOR (i, 1, n)
            table[i][0] = a[i];
        for (int i = 1; MASK(i) <= n; i++)
            for (int j = 1; j + MASK(i) - 1 <= n; j++)
                table[j][i] = minimize(table[j][i - 1], table[j + MASK(i - 1)][i - 1]);
    }

    int get(int left, int right){
        int lg = __lg(right - left + 1);
        return minimize(table[left][lg], table[right - MASK(lg) + 1][lg]);
    }
} spt;