/*************************************
*       author: Pham Huy Khanh       *
*************************************/
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
#define DEBUG(n, a) FOR (i, 1, n) cout << a[i] << ' '; cout << endl;
#define lob lower_bound // i min : V[i] >= val
#define upb upper_bound // i min : V[i] > val
#define endl "\n"

using namespace std;

template<class X, class Y> bool maximize(X &x, Y y){ if (x < y){ x = y; return true; } return false; }
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y){ x = y; return true; } return false; }

#define  gogobruhbruh  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define  file(name)  if (fopen (name".inp", "r")) { freopen (name".inp", "r", stdin); freopen (name".out", "w", stdout); }

const ll MOD = 20215201314;

void add(ll &a, ll b){ if ((a += b) >= MOD) a -= MOD; }
void sub(ll &a, ll b){ if ((a -= b) < 0) a += MOD; }
ll muti(ll a, ll b){ return a * b % MOD; }
int Pow(int a, int b){ int res = 1; for (; b; b >>= 1, a = muti(a, a)) if (b & 1) res = muti(res, a); return res; }

const int MAX = 1e4 + 7;
const int INF = 1e9 + 7;

int num, limit;
vector<pii> V;
int dp[MAX];

void solve(){
    for (auto[val, weight] : V)
        FOD (j, limit, weight)
            maximize(dp[j], dp[j - weight] + val);
    cout << dp[limit];
}

void read(){
    cin >> num >> limit;
    FOR (i, 1, num){
        static int weight, val, amount;
        cin >> weight >> val >> amount;
        for (int j = 0; MASK(j) <= amount; j++)
            V.eb(pii(val * MASK(j), weight * MASK(j))),
            amount -= MASK(j);
        if (amount)
            V.eb(pii(val * amount, weight * amount));
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
