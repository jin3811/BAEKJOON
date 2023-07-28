#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int a1, a0, c, n0;

void sol() {
    int dy = a1 - c;

    if (dy > 0) {
        cout << 0;
    }
    else {
        if (dy * n0 + a0 <= 0) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> a1 >> a0 >> c >> n0;
    sol();
}