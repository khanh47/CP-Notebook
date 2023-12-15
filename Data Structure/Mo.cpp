// tested: 
// https://codeforces.com/contest/86/problem/D
// https://codeforces.com/contest/221/problem/D
// https://codeforces.com/contest/617/problem/E
// https://codeforces.com/contest/375/problem/D
// https://oj.vnoi.info/problem/fc090_coprime
// https://oj.vnoi.info/problem/cowsheds

const int MAX = 1e5 + 7;
const ll INF = 1e18 + 7;
const int S = 333;

int num, query, cur;
int val[MAX], cnt[MAX], res[MAX];
bool ok[MAX];
#define data tuple<int, int, int>
data Q[MAX];

bool cmp(data a, data b){
    auto[l1, r1, i1] = a;
    auto[l2, r2, i2] = b;
    if (l1 / S == l2 / S)
        return r1 / S < r2 / S;
    return l1 / S < l2 / S;
}

void update(int i, int delta){
    if (val[i] > num)
        return;
    cnt[val[i]] += delta;
    if (cnt[val[i]] == val[i] + delta)
        cur -= ok[val[i]],
        ok[val[i]] = 0;
    if (cnt[val[i]] == val[i])
        cur += !ok[val[i]],
        ok[val[i]] = 1;
}

void solve(){
    sort(Q + 1, Q + 1 + query, cmp);
    int l = 1, r = 0;
    FOR (i, 1, query){
        auto[L, R, idx] = Q[i];
        while (r < R)
            update(++r, 1);
        while (l > L)
            update(--l, 1);
        while (l < L)
            update(l++, -1);
        while (r > R)
            update(r--, -1);
        res[idx] = cur;
    }
    FOR (i, 1, query)
        cout << res[i] << endl;
}
