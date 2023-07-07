#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    array<int, 26> arr = {0,};
    string word;
    cin >> word;
    for(const auto& x : word) ++arr[x - 'a'];
    for(const auto& x : arr) cout << x << ' ';
}