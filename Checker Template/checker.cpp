#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= b; i++)
#define NAME "main"

const int TEST = 100;

int main(){
    FOR (i, 1, TEST){
        system(NAME"_gen.exe");
        system(NAME".exe");
        system(NAME"_brute.exe");
        if (system("fc " NAME".out " NAME".ans")){
            cout << "test: " << i << " WA\n";
            return 0;
        }
        cout << "test: " << i << " AC\n";
    }
}
