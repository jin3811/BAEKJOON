#include <bits/stdc++.h>
using namespace std;
#define mod 15746

void sol(int n) {
    vector<int> v = {0, 1, 2};
    for(int i = 3; i <= n; i++) {
        v.push_back((v[i - 1] + v[i - 2]) % mod);
    }
    cout << v[n];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    sol(n);
}