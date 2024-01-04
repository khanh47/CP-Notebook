// Condition:
//   dp[i] = min( dp[j] + w(j, i) )  
//   with j < i
// Condition:
//   w(a, c) + w(b, d) ≤ w(a, d) + w(b, c)
//   with a < b ≤ c < d.

const int MAX = 1e5 + 7;

int num;
int a[MAX], b[MAX];
ll dp[MAX];

struct state {
    int l, r, p;
};

deque<state> dq;

ll cost(int j, int i){
    return 1LL * b[j] * a[i];
}

void update(int i){
    auto [l, r, p] = dq.back();
    int pos = r + 1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (dp[i] + cost(i, mid) < dp[p] + cost(p, mid))
            pos = mid,
            r = mid - 1;
        else
            l = mid + 1;
    }
    dq.back().r = pos - 1;
    if (pos <= num)
        dq.pb({pos, num, i});
}

void solve(){
    dq.pb({2, num, 1});
    FOR (i, 2, num){
        auto &[l, r, p] = dq.front();
        dp[i] = dp[p] + cost(p, i);
        if (++l > r) dq.pop_front();
        while (dq.size()){
            auto [l, r, p] = dq.back();
            if (dp[i] + cost(i, l) < dp[p] + cost(p, l))
                dq.pop_back();
            else
                break;
        }
        if (dq.size())
            update(i);
        else
            dq.pb({i + 1, num, i});
    }
    cout << dp[num];
}