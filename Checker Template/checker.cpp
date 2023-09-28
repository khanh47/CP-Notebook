#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define out(i, v) cout << "Test " << i << ": " << (v ? "AC\n" : "WA\n");
#define NAME "main"

const int TEST = 1e2;

int main(){
    FOR (i, 1, TEST){
        system(NAME"_gen.exe");
        system(NAME".exe");
        system(NAME"_brute.exe");
        if (system("fc " NAME".out " NAME".ans")){
            out(i, 0);
            return 0;
        }
        out(i, 1);
    }
}
