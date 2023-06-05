#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define ll long long
using namespace std;
#define NAME "main"
const int NTEST = 1000;
const int INF = 5e6;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return abs(l + rd() * 1LL * rd() % (h - l + 1));
}

const int MAX = 1e4;

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        system(NAME"_gen.exe");
        system(NAME".exe");
        system(NAME"_brute.exe");
        if (system("fc " NAME".out " NAME".ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
