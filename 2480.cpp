#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 3> coin;
    int same = 0;
    int same_idx = -1;

    for(int& x : coin) cin >> x;

    sort(coin.begin(), coin.end()); // 가장 큰 원소를 찾기 위해 정렬

    for(int i = 0; i < 3; i++) { // 모든 원소끼리 비교하여 같은 것을 센다
        if (coin[i % 3] == coin[(i + 1) % 3]) {
            same++;
            if (same_idx == -1) same_idx = i;
        }
    }

    if(same == 0) cout << 100 * coin[2]; // 다 다름
    else if (same == 1) cout << 1000 + coin[same_idx] * 100; // 같은게 한개
    else cout << 10000 + coin[0] * 1000; // 다 같음
}
