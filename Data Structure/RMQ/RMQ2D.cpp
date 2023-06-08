
#define MASK(i) (1LL << (i))

template<class X, class Y> bool maximize(X &x, Y y){ if (x < y){ x = y; return true; } return false; }
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y){ x = y; return true; } return false; }

const int MAX = 3e2 + 7;
const int LG = 10;

struct rmq2d{
    int table[MAX][LG][MAX][LG], row, col;
    
    void build(){
        for (int k = 0; MASK(k) <= row; k++)
            for (int i = 1; i + MASK(k) - 1 <= row; i++)
                for (int l = 0; MASK(l) <= col; l++)
                    for (int j = 1; j + MASK(l) - 1 <= col; j++){
                        if (!k){
                            if (!l)
                                table[i][0][j][0] = val[i][j];
                            else
                                table[i][0][j][l] = max(table[i][0][j][l - 1], table[i][0][j + MASK(l - 1)][l - 1]);
                        }else
                            table[i][k][j][l] = max(table[i][k - 1][j][l], table[i + MASK(k - 1)][k - 1][j][l]);
                    }
    }    
    
    int get(int x, int y, int a, int b){
        int k = __lg(a - x + 1);
        int l = __lg(b - y + 1);
        int mx = max({ table[x][k][y][l],
                       table[x][k][b - MASK(l) + 1][l],
                       table[a - MASK(k) + 1][k][y][l],
                       table[a - MASK(k) + 1][k][b - MASK(l) + 1][l] });
        return mx;
    }
} rmq;