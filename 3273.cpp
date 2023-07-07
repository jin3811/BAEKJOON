#include <bits/stdc++.h>
using namespace std;

int n, target;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for(int& x : v) cin >> x;
    cin >> target;
    sort(v.begin(), v.end());
}

void sol() {
    int cnt = 0, sum = 0, lo = 0, hi = n - 1;
    while(lo < hi) {
        sum = v[lo] + v[hi];
        if (sum > target) hi--;
        else if (sum < target) lo++;
        else {
            cnt++;
            hi--;
            lo++;
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