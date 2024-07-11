#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n, cnt;


void sol() {
    // uint64_t answer = 4 * n + 1;
    // if (cnt % 2) {
    //     answer 
    // }
    if (cnt == 0) {
        cout << n - 1;
        return;
    }
    
    uint64_t answer = 0;
    map<int, int> hand;
    
    for (int i = 1; i < 5; i++) {
        hand[i] = cnt;
    }
    hand[5] = (n + 1) / 2;
    
    if (cnt != 1) {
        if (cnt % 2 == 1) {
            hand[1]--;
        }
    }

    if (cnt % 2 == 1) {
        for (int i = 4; i >= 1; i--) {
            if (i == n && hand[i] == cnt) break;
            hand[i]++;
        }
    }
    else {
        for (int i = 2; i <= 5; i++) {
            if (i == n && hand[i] == cnt) break;
            hand[i]++;
        }
    }

    for (auto& [a, b] : hand) {
        answer += b * 1L;
    }

    cout << answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> cnt;
    sol();
}