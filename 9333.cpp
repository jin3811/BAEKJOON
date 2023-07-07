#include <bits/stdc++.h>
#define endl '\n'
#define FAIL "impossible"
#define DECIMALERROR 1e-7
using namespace std;
using pii = pair<int, int>;

pii

void sol(unsigned long long b, const long long m, double r) {
    if (round(b * r / 100 + DECIMALERROR) >= m) {// 이자가 납부금보다 같거나 많으면 이자에 허덕이며 못갚는다.
        cout << FAIL << endl;
        return;
    }

    // unsigned long long rest = b;

    for (int i = 1; i <= 1200; i++) {
        // rest += (unsigned long long)(rest * r / 100 + 0.5); // 이자 곱하고 반올림
        // rest -= m; // 상환
        // if (rest <= 0) {

        if (b <= 0) {
            cout << i << endl; // 다 갚았으면 끝
            return;
        }
    }
    cout << FAIL << endl; // 반복문 안에서 return이 안됐으면 실패
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    string b, r, m; // 원금, 이자, 소득

    cin >> tc;

    while(tc--) {
       cin >> r >> b >> m;

    }
}