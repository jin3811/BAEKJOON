#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int l, n;

void input() {
    cin >> l >> n;
}

void sol() {
    cout << min(l - n, n - 1) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}