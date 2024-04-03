#include <bits/stdc++.h>
int kth(std::vector<int> &a, int k) {
    std::random_shuffle(a.begin(), a.end()); // 12퍼에서 TLE 나기 때문에 랜덤으로 함 스까줘야함
    std::nth_element(a.begin(), a.begin()+k-1, a.end());
    return a[k-1];
}