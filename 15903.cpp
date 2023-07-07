#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void input() {
    int input;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input;
        pq.push(input);
    }
}

void sol() {
    int a, b;
    int result = 0;
    for(int i = 0; i < m; i++) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    while(!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}