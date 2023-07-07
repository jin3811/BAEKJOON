#include <bits/stdc++.h>
using namespace std;

int main () {
    cin.tie(nullptr)->sync_with_stdio(false);;
    int n, k;
    cin >> n >> k;
    vector<int> score(n);
    for(int& x : score) cin >> x;
    sort(score.rbegin(), score.rend());
    cout << score[k-1];
}