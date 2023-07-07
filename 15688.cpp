#include <iostream>
#include <vector>
#include <algorithm>
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
    sort(v.begin(), v.end());
    for (auto& x : v) cout << x << '\n';
}