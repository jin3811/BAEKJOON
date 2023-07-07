#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    int temp;
    vector<int> v;
    cin >> t;

    while (t--) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), greater<>());
    for (auto& x : v) cout << x << '\n';
}