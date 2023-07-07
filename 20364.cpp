#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q, num, temp;
    int ans = 0;
    cin >> n >> q;
    bool* land_tree = new bool[n + 1]; // true: 차지됨, false: 비어있음
    
    while(q--) {
        cin >> num;
        ans = 0;
        temp = num;
        while(temp) {
           if (land_tree[temp]) ans = temp;
           temp >>= 1;
        }
        if (!ans) land_tree[num] = true;
        cout << ans << '\n';
    }
}