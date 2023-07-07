#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a%b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;

    cin >> n;
    while(n--) {
        cin >> a >> b;
        cout << (a * b) / gcd(a, b) << '\n';
    }
}