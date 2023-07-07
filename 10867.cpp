#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v;
    int n, temp;
    cin >> n;
    while(n--) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto& x : v) cout << x << ' ';
}