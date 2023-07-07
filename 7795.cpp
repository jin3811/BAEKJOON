#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int nA, nB;
vector<int> a, b;

void input() {
    cin >> nA >> nB;
    a.clear(); b.clear();
    a.resize(nA); b.resize(nB);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void sol() {
    int result = 0;
    for(int& x : a) {
        result += lower_bound(b.begin(), b.end(), x) - b.begin();
    }
    cout << result << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        input();
        sol();
    }
}