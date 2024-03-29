#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, m, n;

double giveNPU(int m, int n) {
    double cases[3] = {2. * m / a, max((double)m/a, (double)n), 2. * n};
    sort(cases, cases+3);
    return cases[0];
}

void sol() {
    cout << fixed;
    cout.precision(7);
    cout << min(giveNPU(m, n), giveNPU(n, m));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> a >> m >> n;
    sol();
}