#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    vector<int> v;

    cin >> n >> k;

    v.resize(n);
    iota(v.begin(), v.end(), 1);

    cout << "<";
    while(!v.empty()) {
        rotate(v.begin(), v.begin() + ((k - 1) % v.size()), v.end());
        cout << v[0];
        if (v.size() > 1) cout << ", ";
        rotate(v.begin(), v.begin() + 1, v.end());
        v.pop_back();
    }
    cout << ">";
}