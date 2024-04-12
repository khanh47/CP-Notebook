const int MAX = 100;

struct matrix {
    int a[MAX][MAX];
    int row, col;

    matrix(int _row, int _col){
        row = _row; col = _col;
        FOR (i, 0, row - 1)
            FOR (j, 0, col - 1)
                a[i][j] = 0;
    }

    matrix operator * (matrix b){
        // assert(col == b.row);
        matrix res(row, b.col);
        FOR (i, 0, row - 1)
            FOR (j, 0, res.col - 1)
                FOR (k, 0, col - 1)
                    add(res.a[i][j], muti(a[i][k], b.a[k][j]));
        return res;
    }
};

matrix pow(matrix a, ll b){
    // assert(a.row == a.col);
    matrix res(a.row, a.col);
    FOR (i, 0, res.row - 1)
        res.a[i][i] = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            res = res * a;
    return res;
}