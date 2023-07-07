#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for(int& x : v) cin >> x;
}

void sol() {
    pair<int, int> answer;
    int diff = 2e9 + 1;
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;

    cout << "sorted : ";
    for(int x : v) cout << x << " ";
    cout << "\n";

    while(l <= r) {
        if(v[r] - v[l] < diff) {
            answer.first = v[r];
            answer.second = v[l];
            diff = v[r] - v[l];
            l++;
        }
        else {
            r--;
        }
    }

    cout << answer.first << " " << answer.second;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}