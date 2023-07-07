#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for(auto& x : v) cin >> x;
}

int maximizeDiff(vector<int>& v){
    int diff = 0;
    for(int i = 1; i < n; i++) diff += (int)abs(v[i - 1] - v[i]);
    return diff;
}

void sol() {
    sort(ALL(v));
    int maxDiff = -1;
    do {
        maxDiff = max(maxDiff, maximizeDiff(v));
    }while (next_permutation(ALL(v)));
    cout << maxDiff;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}