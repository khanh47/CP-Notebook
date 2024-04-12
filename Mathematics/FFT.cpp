#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (int i = (0), _n = (n); i < _n; i++)
#define MASK(i) (1LL << (i))
#define eb emplace_back
#define endl "\n"

using namespace std;

#define PI acos(-1)
#define base complex<double>
#define vb vector<base>

int A, B;
vb a, b;

void fft(vb &val, bool inv){
    int n = val.size();
    if (n == 1) return;
    for (int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(val[i], val[j]);
    }
    for (int len = 2; len <= n; len <<= 1){
        double ang = 2 * PI / len * (inv ? -1 : 1);
        base wn(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len){
            base w(1);
            REP (j, len >> 1){
                base u = val[i + j], v = val[i + j + len / 2] * w;
                val[i + j] = u + v;
                val[i + j + len / 2] = u - v;
                w *= wn;
            }
        }
    }
    if (inv)
        REP (i, n)
            val[i] /= n;
}

vector<ll> muti(vb a, vb b){
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    a.resize(n); b.resize(n);
    fft(a, 0); fft(b, 0);
    REP (i, n)
        a[i] *= b[i];
    fft(a, 1);
    vector<ll> res(n);
    REP (i, n)
        res[i] = round(real(a[i]));
    return res;
}

void solve(){
    vector<ll> res = muti(a, b);
    REP(i, A + B)
        cout << res[i] << ' ';
}

void read(){
    cin >> A >> B;
    a.resize(A); b.resize(B);
    REP(i, A)
        cin >> a[i];
    REP(i, B)
        cin >> b[i];    
}

int main(){
    read();
    solve();
}