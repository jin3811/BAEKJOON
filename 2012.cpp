#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    long long ans = 0;
    vector<int> v;
    
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < tc; i++) {
        ans += abs(v[i] - i - 1);
    }

    cout << ans;
}