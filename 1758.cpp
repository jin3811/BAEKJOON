#include <bits/stdc++.h>
#define ALL(X) X.rbegin(), X.rend()
using namespace std;

int n;
vector<int> customer;

void input() {
    cin >> n;
    customer.resize(n);
    for (int& x : customer) cin >> x;
    sort(ALL(customer));
}

void sol() {
    uint64_t res = 0;
    for (int i = 0; i < n; i++) {
        if (customer[i] - i < 0) break;
        res += customer[i] - i;
    }
    cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}