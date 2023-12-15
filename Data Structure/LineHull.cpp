/*
 * Complexity: O(N, logN)
 * Condition: a * x + b (min)
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
        int left = 0, right = env.size() - 1;
        int res = 0;
        while (left < right){
            int mid = (left + right) >> 1;
            if (ord(env[mid], coord) > ord(env[mid + 1], coord))
                left = mid + 1,
                res = left;
            else
                right = mid;
        }
        return ord(env[res], coord);
    }

    void add(ll a, ll b){
        Line newLine = Line(a, b);
        while (env.size() >= 2 && bad(env[env.size() - 2], env[env.size() - 1], newLine))
            env.pop_back();
        env.pb(newLine);
    }
} hull;