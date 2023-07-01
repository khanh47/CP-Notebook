// Original Recurrence:
// 1.
//   dp[i] = min( dp[j] + b[j]*a[i] )  for j < i
// Condition:
//   b[j] >= b[j+1]
//   a[i] <= a[i+1]
// 2.
//   dp[i] = max( dp[j] + b[j]*a[i] )  for j < i
// Condition:
//   b[j] <= b[j+1]
//   a[i] <= a[i+1]

struct ConvexHullTrick {
    #define Line pair<ll, ll>
    vector<Line> env;
    int idx = 0;

    ll ord(Line line, ll x){
        return line.fi * x + line.se;
    }

    bool bad(Line a, Line b, Line c){
        return (double) (b.se - a.se) * (a.fi - c.fi) >= (double) (c.se - a.se) * (a.fi - b.fi);
    }

    ll getMin(ll x){
        int sz = env.size();
        if (idx >= sz)
            idx = sz - 1;
        while (idx < sz - 1 && ord(env[idx + 1], x) <= ord(env[idx], x))
            idx++;
        return ord(env[idx], x);
    }

    void add(ll a, ll b){
        Line newLine = Line(a, b);
        while (env.size() >= 2 && bad(env[env.size() - 2], env[env.size() - 1], newLine))
            env.pop_back();
        env.pb(newLine);
    }
} cht;