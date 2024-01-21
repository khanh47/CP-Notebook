#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,b,a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = (0), _n = (n); i < _n; i++)

using namespace std;

const int MAX = 1e4 + 7;
const int INF = 1e9 + 7;

#define base complex<double>
#define vb vector<base>
#define PI acos(-1)

int A, B;
vb a, b;

void fft(vb &res, bool inv){
    int n = res.size();
    if (n == 1) return;
    vb even, odd;
    REP(i, n)
        if (i & 1)
            odd.eb(res[i]);
        else
            even.eb(res[i]);
    fft(even, inv);
    fft(odd, inv);
    double ang = 2 * PI / n * (inv ? -1 : 1);
    base w(1), wn(cos(ang), sin(ang));
    REP(i, n >> 1){
        res[i] = even[i] + w * odd[i];
        res[i + n / 2] = even[i] - w * odd[i];
        w *= wn;
        if (inv)
            res[i] /= 2,
            res[i + n / 2] /= 2;
    }
}

vector<int> muti(vb a, vb b){
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    a.resize(n); b.resize(n);
    fft(a, 0);
    fft(b, 0);
    REP (i, n)
        a[i] *= b[i];
    fft(a, 1);
    vector<int> res(n);
    REP(i, n)
        res[i] = real(a[i]);
    return res;
}

void solve(){
    vector<int> res = muti(a, b);
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
    gogobruhbruh;
    file("main");
    int test = 1;
    // cin >> test;
    while (test--)
        read(),
        solve();
}
