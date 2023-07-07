#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, idx = 1, sum = 0;
    vector<int> v;

    while (v.size() != 1000) {
        for (int i = 1; i <= idx; ++i){
            v.push_back(idx);
            if (v.size() == 1000) break;
        }
        ++idx;
    }
    cin >> a >> b;
    for (int i = a-1; i < b; ++i)
        sum += v[i];
    cout << sum;
}