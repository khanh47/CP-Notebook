// Condition:
//   dp[i] = min( dp[j] + w(j, i) )  
//   with j < i
// Condition:
//   w(a, c) + w(b, d) ≤ w(a, d) + w(b, c)
//   with a < b ≤ c < d.

const int MAX = 1e5 + 7;
const ll INF = 1e18 + 7;

int num;
int a[MAX], b[MAX];
ll dp[MAX];

struct Data {
    int l, r, p;
};

deque<Data> dq;

ll calc(int j, int i){
    return 1LL * b[j] * a[i];
}

void update(int i){
    auto &[l, r, p] = dq.back();
    int left = l, right = r, pos = r + 1;
    while (left <= right){
        int mid = (left + right) >> 1;
        if (dp[i] + calc(i, mid) < dp[p] + calc(p, mid)){
            pos = mid;
            right = mid - 1;
        }else
            left = mid + 1;
    }
    r = pos - 1;
    if (pos <= num)
        dq.pb({pos, num, i});
}

void solve(){
    dq.pb({2, num, 1});
    FOR (i, 2, num){
        dp[i] = dp[dq.front().p] + calc(dq.front().p, i);
        dq.front().l++;
        if (dq.front().l > dq.front().r)
            dq.pop_front();
        while (dq.size()){
            auto [l, r, p] = dq.back();
            if (dp[i] + calc(i, l) < dp[p] + calc(p, l))
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