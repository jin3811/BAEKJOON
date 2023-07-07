#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> rope;

void input() {
    int temp;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        rope.push_back(temp);
    }
    sort(rope.begin(), rope.end(), greater<>());
}

void sol() {
    for(int i = 0; i < n; i++) {
        rope[i] *= i + 1;
    }
    cout << *max_element(rope.begin(), rope.end());
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}