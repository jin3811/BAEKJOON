#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000

array<array<int, 401>, 401> memo;

int solution(int n, int r) {
    if (memo[n][r]) return memo[n][r];
    else{
        memo[n][r] = (solution(n - 1, r - 1) % mod + solution(n - 1, r) % mod) % mod;
        return memo[n][r];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 201; i++) { // memo array init
        memo[i][0] = memo[i][i] = 1;
    }

    int n, r;
    cin >> n >> r;
    cout << solution(n + r - 1, r - 1);
}