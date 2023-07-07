#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, cost;
    int count = 0;
    vector<int> coin;

    cin >> t >> cost;

    coin.resize(t);

    for(int& x : coin) cin >> x;

    for(auto iter = coin.rbegin(); iter != coin.rend(); iter++) {
        count += cost / *iter;
        cost %= *iter;
    }
    cout << count;
}