deque<int> Qmn, Qmx;

bool Add(int u) {
    while (Qmn.size() && a[Qmn.back()] >= a[u])
        Qmn.pop_back();
    while (Qmx.size() && a[Qmx.back()] <= a[u])
        Qmx.pop_back();
    Qmn.push_back(u);
    Qmx.push_back(u);
    int mn = a[Qmn.front()];
    int mx = a[Qmx.front()];
}