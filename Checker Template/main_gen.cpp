#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define DEBUG(n, a) FOR (i, 1, n) cout << a[i] << ' '; cout << endl;
#define ll long long

// weak random value but strong accuracy

int ran(int l, int r){
    assert(l <= r);
    return l + rand() % (r - l + 1);
}

mt19937 rd(chrono::steady_clock::now()::time_since_epoch().count());

#define rand rd

// strong random value but weak accuracy 
// (often generate 0 although we use Ran(1, n) with n >= 1)
ll Ran(ll l, ll r){
    assert(l <= r);
    return abs(l + rd() * 1LL * rd() % (r - l + 1));
}

int main(){
    srand(time(NULL));
    ofstream inp(NAME".inp");
    // generate input code goes here
}
