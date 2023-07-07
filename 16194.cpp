#include <bits/stdc++.h>
using namespace std;

vector<int> P;
// vector<vector<int>> memo;
int n;

void input() {
    cin >> n;
    // memo.resize(n + 1);    
    P.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> P[i];
}

// int dp(int x, int card_cnt) {
//     if (card_cnt == n) return P[x];
//     fill(memo.begin(), memo.end(), 0);
//     int cost = 2e4;
//     for (int i = 1; i <= n - card_cnt; i++) {
//         if (!memo[i][card_cnt + i]) {
//             memo[i][card_cnt + i] = dp(i, card_cnt+ i);
//         }
//         cost = min(cost, P[x] + memo[i][card_cnt + i]);
//     }
//     return cost;
// }
// void sol() {
//     int min_pay = 2e9;
//     for (int i = 1; i <= n; i++) {
//         min_pay = min(min_pay, dp(i, i));
//     }
//     cout << min_pay;
// }

void sol() {
    vector<int> dp(n + 1, 1e4 + 1); 
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j] + P[j]);
        }
    }
    cout << dp[n];
}

#define CASEN 7
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef BOJ // 테케 검증용 조건부 컴파일
    for (int i = 0; i < CASEN; i++) {
        input();
        sol();
        cout << '\n';
        P.clear();
    }
    #endif
    #ifdef BOJ
        input();
        sol();
    #endif
}