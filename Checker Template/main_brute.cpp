/*************************************
*       author: Pham Huy Khanh       *
*************************************/
#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,b,a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define CNTBIT(x) __builtin_popcountll(x)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define left ___left
#define right ___right
#define pii pair<int, int>
#define endl "\n"
#define DEBUG(n, a) FOR (i, 1, n) cout << a[i] << ' '; cout << endl;
#define NAME "main"

using namespace std;

template<class X, class Y> bool maximize(X &x, Y y){ if (x < y){ x = y; return true; } return false; }
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y){ x = y; return true; } return false; }

#define  gogobruhbruh  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define  file(name)  if (fopen (name".inp", "r")) { freopen (name".inp", "r", stdin); freopen (name".ans", "w", stdout); }

const int MOD = 1e9 + 7;

void add(int &a, int b){ if ((a += b) >= MOD) a -= MOD; }
void sub(int &a, int b){ if ((a -= b) < 0) a += MOD; }
int muti(int a, int b){ return 1LL * a * b % MOD; }
int Pow(int x, int y){ int res = 1; for (; y; y >>= 1){ if (y & 1) res = muti(res, x); x = muti(x, x); } return res; }

const int MAX = 5e1 + 7;
const ll INF = 1e18 + 7;

void solve(){
}

void read(){
}

int main(){
    gogobruhbruh
    file("main");
    int test = 1;
    // cin >> test;
    while (test--)
      read(),
      solve();
}
