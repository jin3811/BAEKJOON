#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m, t;
    cin >> h >> m >> t;

    m += t % 60;
    h += (t / 60) + (m / 60);
    m %= 60;
    h %= 24;
    cout << h << ' ' << m;
}