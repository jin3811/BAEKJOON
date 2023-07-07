#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> v;
    vector<int>::iterator iter;
    cin >> n;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), greater<>());
    
    for (iter = v.begin(); iter != v.end(); iter++)
        cout << *iter;
}