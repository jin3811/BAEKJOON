#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    
    cin >> n >> m;

    for (int i = 1; i <= n*m; ++i) {
        cout << i;
        if (i % m) cout << ' ';
        else cout << '\n';
    }
}