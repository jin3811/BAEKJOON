#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test, n; // test case, input
    vector<pair<int, int>> v(41);
    pair<int, int> result;
    
    v[0] = make_pair(1, 0); // init vector
    v[1] = make_pair(0, 1);
    for (int i = 2; i < 41; ++i)
        v[i] = make_pair(v[i-2].first + v[i-1].first, v[i-2].second + v[i-1].second);
    
    cin >> test;
    while (test--) {
        cin >> n;
        cout << v[n].first << ' ' << v[n].second << '\n';
    }
}