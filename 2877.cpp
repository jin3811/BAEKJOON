#include <bits/stdc++.h>
#define endl '\n'
#define ALL(X) (X).begin(), (X).end()
using namespace std;

void sol(int k) {
    // k = 2(2^n - 1) + c 로 분해
    int n = (int)log2((k - 1) / 2. + 1);
    int c = k - (int)pow(2, n) * 2 + 1;
    string answer = "";
    bitset<32> ans_bit = c;
    
    for (int i = 0; i <= n; i++) {
        if (ans_bit[i]) answer.append("7");
        else answer.append("4");
    }
    reverse(ALL(answer));
    cout << answer << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    int k; cin >> k;
    sol(k);
}