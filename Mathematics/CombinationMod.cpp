
int fact[MAX], finv[MAX];

int C(int k, int n){
    if (k > n)
        return 0;
    return 1LL * fact[n] * finv[k] % MOD * finv[n - k] % MOD;
}

void build(){
    fact[0] = 1;
    FOR (i, 1, MAX - 1)
        fact[i] = muti(fact[i - 1], i);
    // (a / b) % MOD = (a * b^(MOD - 2)) % MOD
    finv[MAX - 1] = Pow(fact[MAX - 1], MOD - 2);
    FOD (i, MAX - 1, 1)
        finv[i - 1] = muti(finv[i], i);
}