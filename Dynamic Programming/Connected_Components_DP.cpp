// https://codeforces.com/blog/entry/92602
// dp(i, j) store how many way to arrange first i numbers in j components
// dp(i, j) += dp(i - 1, j - 1) * j : add a new component from j - 1 components : j avalieble positions (between adjacent components or before first components or after last components)
// dp(i, j) += dp(i - 1, j) * 2 * j : add number i into any existing components from j components : 2 * j avalieble positions (before or after any components)
// dp(i, j) += dp(i - 1, j + 1) * j : merge two components from j + 1 components : j avalieble positions (between adjacent components)

const int MOD = 1e9 + 7;

void add(int &a, int b){ if ((a += b) >= MOD) a -= MOD; }
int muti(int a, int b){ return (1LL * a * b) % MOD; }

const int MAX = 1e3 + 7;

int num;
int dp[MAX][MAX];

void solve(){
    dp[0][0] = 1;
    FOR (i, 1, num)
        FOR (j, 1, num){
            dp[i][j] = muti(dp[i - 1][j - 1], j);
            add(dp[i][j], muti(dp[i - 1][j], muti(2, j)));
            add(dp[i][j], muti(dp[i - 1][j + 1], j));
        }
    cout << dp[num][1];
}
