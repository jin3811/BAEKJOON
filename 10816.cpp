#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, temp;
    vector<int> v;

    cin >> t;
    while (t--) {
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());   

    cin >> t;
    while (t--) {
        cin >> temp;
        cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << ' ';
    }
}