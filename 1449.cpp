#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> hole;

void input() {
    cin >> n >> l;
    hole.resize(n);
    for(int& x : hole) cin >> x;
    sort(hole.begin(), hole.end());
}

void sol() {
    int cnt = 1;
    int start = hole[0];

    for(int i = 1; i < n; i++) {
        if(hole[i] - start + 1 > l) {
            cnt++;
            start = hole[i];
        }
    }
    cout << cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}