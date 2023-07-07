#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int len, temp;
    vector<int> v;
    cin >> len;
    
    while (len--) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin >> len;
    while (len--) {
        cin >> temp;
        cout << binary_search(v.begin(), v.end(), temp) << ' ';
    }
}