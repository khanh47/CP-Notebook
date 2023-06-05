ll d[103][103], a[103][103], t[103][103];
int n;

void solve(){
    FOR (i, 1, n)
        FOR (j, 1, n){
            d[i][j] = a[i][j];
            t[i][j] = i;
            if (i == j)
                continue;
            if (!a[i][j])
                d[i][j] = INT_MAX;
        }
    FOR (k, 1, n)
        FOR (i, 1, n)
            FOR (j, 1, n)
                if (d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    t[i][j] = t[k][j];
                }
}

void trace(int u, int v){
    int d = 0;
    string s;
    while (true){
        d++;
        s = to_string(v) + " " + s;
        if (v == u)
            break;
        v = t[u][v];
    }
    cout << d << ' ' << s << endl;
}

void read(){
    cin >> n >> m >> k;
    FOR (i, 1, m){
        int x, y, c;
        cin >> x >> y >> c;
        a[x][y] = a[y][x] = c;
    }
}