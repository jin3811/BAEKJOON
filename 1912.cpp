#include <bits/stdc++.h>
using namespace std;

int* arr;
int* dp;
int n;

void input() {
    cin >> n;
    arr = new int[n];
    dp = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
}

void solution() {
    int ans = *dp;
    for(int i = 1; i < n; i++) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
    delete[] arr;
    delete[] dp;
}