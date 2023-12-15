
string s, t;
int nxt[MAX][26];

void solve(){
    memset(nxt, 0, sizeof(nxt));
    cin >> s >> t;
    int n = s.size(), m = t.size();
    FOR (i, 0, m - 2){
        int pre = nxt[i][t[i] - 'a'];
        nxt[i][t[i] - 'a'] = i + 1;
        FOR (j, 0, 25)
            nxt[i + 1][j] = nxt[pre][j];
    }
    nxt[m - 1][t[m - 1] - 'a'] = m;
}