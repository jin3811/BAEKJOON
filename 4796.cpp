#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, p, v, result;
    int case_num = 1;

    while(true) {
        result = 0;
        cin >> l >> p >> v;
        if(!l && !p && !v) break;
        
        result = ((v / p) * l) + min(v % p, l);
        cout << "Case " << case_num++ << ": " << result << "\n";
    }
}