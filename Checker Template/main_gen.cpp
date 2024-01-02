#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(i,a,b) for (int i = _a, _b = (b); i <= b; i++)
#define FOD(i,a,b) for (int i = _a, _b = (b); i >= b; i--)
#define NAME "main"

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rand rd

ll Rand(ll l, ll r){
    return l + rd() * 1LL * rd() % (r - l + 1);
}

ofstream inp(NAME".inp");

int main(){
    srand(time(NULL));
    inp << Rand(0, 100);
}
