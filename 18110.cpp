#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for(int& i : v) cin >> i;
    sort(ALL(v));
}

void sol() {
    if (n == 0) {
        cout << 0;
        return;
    }

    int avg = 0;
    int cut = (n * 15 + 50) / 100;
    int cnt = n - 2 * cut;

    for (int i = cut; i < v.size() - cut; i++) {
        avg += v[i];
    }
    
    avg = (avg + cnt / 2) / cnt;
    cout << avg;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}