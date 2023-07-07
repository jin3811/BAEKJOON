#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int rgb_cost[3];
    int house[1001][3] = {0, 0, 0, };
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) cin >> rgb_cost[j];
        for(int j = 0; j < 3; j++) {
            house[i][j] = min(house[i - 1][(j + 1) % 3], house[i - 1][(j + 2) % 3]) + rgb_cost[j];
        }
    }
    cout << min(min(house[n][0], house[n][1]), house[n][2]);
}