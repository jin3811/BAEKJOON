#include <bits/stdc++.h>
using namespace std;

uint64_t sol(int n) {
    uint64_t dp[91] = {0, 1, 1};
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cout << sol(n);
} 