const int MAX = 2e5 + 7;
const int S = 34e2; // pow(MAX, 2 / 3)

int num, query, l, r, cur;
int a[MAX], last[MAX];
ll res, ans[MAX];

struct Query {
    int l, r, t, id;
};

bool cmp(Query a, Query b){
    if (a.l / S != b.l / S) return a.l < b.l;
    if (a.r / S != b.r / S) return a.r < b.r;
    return a.t < b.t;
}

struct Update {
    int pos, pre, now;
};

vector<Query> q;
vector<Update> u;

void add(int x){
    res += a[x];
}

void sub(int x){
    res -= a[x];
}

void change(int i, int x){
    if (l <= i && i <= r){
        sub(i);
        a[i] = x;
        add(i);
    }else
        a[i] = x;
}

void solve(){
    sort(ALL(q), cmp);
    l = 1;
    for (auto [L, R, t, id] : q){
        while (cur < t){
            cur++;
            change(u[cur].pos, u[cur].now);
        }
        while (cur > t){
            change(u[cur].pos, u[cur].pre);
            cur--;
        }
        while (r < R)
            add(++r);
        while (l > L)
            add(--l);
        while (r > R)
            sub(r--);
        while (l < L)
            sub(l++);
        ans[id] = res;
    }
    FOR (i, 1, q.size())
        cout << ans[i] << endl;
}

void read(){
    cin >> num >> query;
    FOR (i, 1, num)
        cin >> a[i],
        last[i] = a[i];
    u.pb({-1, -1, -1});
    while (query--){
        static int t, l, r;
        cin >> t >> l >> r;
        if (t & 1){
            u.pb({l, last[l], r});
            last[l] = r;
        }else
            q.pb({l, r, u.size() - 1, q.size() + 1});
    }
}