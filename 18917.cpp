#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int query, x, test_case;
    ll xor_val = 0;
    ll sum = 0;

    cin >> test_case;

    while(test_case--) {
        cin >> query;

        if (query == 1){
            cin >> x;
            sum += x;
            xor_val ^= x;
        }
        else if (query == 2){
            cin >> x;
            sum -= x;
            xor_val ^= x;
        }
        else if (query == 3){
            cout << sum << '\n';
        }
        else if (query == 4){
            cout << xor_val << '\n';
        }
         
    }
}