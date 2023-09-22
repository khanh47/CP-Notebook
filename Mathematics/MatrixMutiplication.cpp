#define Matrix vector<vector<int>>
#define row(a) a.size()
#define col(a) a[0].size()
#define init(r, c) Matrix(r, vector<int>(c, 0))

Matrix identity(int n){
    Matrix res = init(n, n);
    while (n--) res[n][n] = 1;
    return res;
}

Matrix muti(Matrix a, Matrix b){
    assert(col(a) == row(b));
    Matrix res = init(row(a), col(b));
    FOR (i, 0, row(a) - 1)
        FOR (j, 0, col(b) - 1)
            FOR (k, 0, col(a) - 1)
                add(res[i][j], muti(a[i][k], b[k][j]));
    return res;
}

Matrix pow(Matrix a, ll b){
    assert(row(a) == col(a));
    Matrix res = identity(row(a));
    for (; b; b >>= 1, a = muti(a, a))
        if (b & 1)
            res = muti(res, a);
    return res;
}