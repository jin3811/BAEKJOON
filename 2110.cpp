#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v;
    vector<int>::iterator iter;
    int n, c, prev, cnt;
    int start, mid, end, result = 0;
    
    cin >> n >> c;
    v.resize(n);

    for(iter = v.begin(); iter != v.end(); ++iter) {
        cin >> *iter;
    }
    sort(v.begin(), v.end());

    start = 1;
    end = v[n - 1] - v[0];
    
    while (start <= end) {
        mid = (start + end) >> 1;
        cnt = 1;
        prev = v[0];

        for(iter = v.begin() + 1; iter != v.end(); ++iter){
            if(*iter - prev >= mid) {
                ++cnt;
                prev = *iter;
            }
        }
        if (cnt >= c) {
            start = mid + 1;
            result = mid;
        }
        else end = mid - 1;
    }
    cout << result;
}