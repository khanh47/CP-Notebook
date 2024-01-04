const int MOD = 1e5 + 3;

int fact[MOD], finv[MOD];

int C(int k, int n){
    if (k > n) return 0;
    return 1LL * fact[n] * finv[k] % MOD * finv[n - k] % MOD;
}

int lucas(ll k, ll n){
    if (k > n) return 0;
    int res = 1;
    for (; n; n /= MOD, k /= MOD)
        res = muti(res, C(k % MOD, n % MOD));
    return res;
}

void build(){
    fact[0] = 1;
    FOR (i, 1, MOD - 1)
        fact[i] = muti(fact[i - 1], i);
    finv[MOD - 1] = Pow(fact[MOD - 1], MOD - 2);
    FOD (i, MOD - 1, 1)
        finv[i - 1] = muti(finv[i], i);
}