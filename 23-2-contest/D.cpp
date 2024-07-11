#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for (int& n : v) cin >> n;
}

void sol(int i) {
    int answer = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] + v[j] == 196) answer++;
        }
    }
    cout << "Case #" << i << " : " << answer << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        input();
        sol(i);
    }
}