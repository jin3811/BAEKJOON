#include <bits/stdc++.h>
using namespace std;
#define MOD 10007

int sol(int n) {
    int dp[10];
    fill(dp, dp + 10, 1);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            dp[j + 1] += dp[j] % MOD;
            dp[j + 1] %= MOD;
        }
    }
    return accumulate(dp, dp + 10, 0) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << sol(n);
}
