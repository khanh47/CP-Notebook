/*
 * Complexity: O(N, logN)
 * Problems:
 * 1. http://codeforces.com/contest/631/problem/E
 * 2. http://codeforces.com/contest/660/problem/F
 * 3. http://codeforces.com/gym/100739/problem/K
 * 4. http://codeforces.com/contest/455/problem/E
 * 5. https://www.codechef.com/problems/CYCLRACE
 */

const int MAX = 1e5 + 7;

struct LineHull {
    #define Line pair<ll, ll>
    Line env[MAX];

    ll ord(Line line, ll x){
        return line.fi * x + line.se;
    }

    bool bad(Line a, Line b, Line c){
        return (double) (b.se - a.se) * (a.fi - c.fi) >= (double) (c.se - a.se) * (a.fi - b.fi);
    }

    ll getMin(ll coord) {
        int left = 0, right = top - 1;
        ll res = ord(env[left], coord);
        while (left < right){
            int mid = (left + right) >> 1;
            ll x = ord(env[mid], coord);
            ll y = ord(env[mid + 1], coord);
            if (x > y)
                left = mid + 1;
            else
                right = mid;
            res = min(res, min(x, y));
        }
        return res;
    }

    void add(ll a, ll b){
        Line newLine = Line(a, b);
        while (env.size() >= 2 && bad(env[env.size() - 2], env[env.size() - 1], newLine))
            env.pop_back();
        env.pb(newLine);
    }
} hull;