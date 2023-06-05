#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,b,a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define CNTBIT(x) __builtin_popcount(x)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define left ___left
#define right ___right
#define pii pair<int, int>
#define pll pair<ll, ll>
#define DEBUG(n, a) FOR (i, 1, n) cout << a[i] << ' '; cout << endl;
#define lob lower_bound // >=
#define upb upper_bound // >
#define endl "\n"
#define NAME "main"

using namespace std;

template<class X, class Y> bool maximize(X &x, Y y){ if (x < y){ x = y; return true; } return false; }
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y){ x = y; return true; } return false; }

#define  gogobruhbruh  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define  file(name)  if (fopen (name".inp", "r")) { freopen (name".inp", "r", stdin); freopen (name".out", "w", stdout); }

const int MOD = 1e9 + 7;

int add(int a, int b){ if ((a += b) >= MOD) a -= MOD; return a; }
int sub(int &a, int b){ if ((a -= b) < 0) a += MOD; return a; }
int muti(int a, int b){ return (1LL * a * b) % MOD; }
int Pow(int x, int y){ int res = 1; for (; y; y >>= 1){ if (y & 1) res = muti(res, x); x = muti(x, x); } return res; }

const int MAX = 1e4 + 7;
const int INF = 1e9 + 7;

int num, limit;
vector<pii> V;
int dp[MAX];

void solve(){
    for (auto[val, weight] : V)
        FOD (j, limit, weight)
            maximize(dp[j], dp[j - weight] + val);
    printf("%d", dp[limit]);
}

void read(){
    scanf("%d %d", &num, &limit);
    FOR (i, 1, num){
        static int weight, val, amount;
        scanf("%d %d %d", &weight, &val, &amount);
        for (int j = 0; MASK(j) <= amount; j++)
            V.pb({val * MASK(j), weight * MASK(j)}),
            amount -= MASK(j);
        if (amount)
            V.pb({val * amount, weight * amount});
    }
}

int main(){
    gogobruhbruh;
    file("main");
    int test = 1;
//    cin >> test;
    while (test--)
        read(),
        solve();
}
