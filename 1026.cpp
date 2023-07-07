#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, temp, result = 0;
    vector<int> a;
    vector<int> b;
    vector<int>::iterator iter;

    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; ++i){
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        iter = max_element(b.begin(), b.end());
        result += a[i] * *iter;
        *iter = 0;
    }

    cout << result;
}