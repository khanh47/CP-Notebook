#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define DEBUG(n, a) FOR (i, 1, n) cout << a[i] << ' '; cout << endl;
#define ll long long
#define NAME "main"

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rd rand

ll Rand(ll l, ll r){
    assert(l <= r);
    return l + rd() * 1LL * rd() % (r - l + 1);
}

ll pos(ll l, ll r){
    assert(l <= r);
    return abs(l + rd() * 1LL * rd() % (r - l + 1));
}

ofstream inp(NAME".inp");

int main(){
}
