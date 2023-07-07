#include <bits/stdc++.h>
using namespace std;

int sum_pv(string& str){
    int sum = 0;
    for(char& x : str) {
        sum += x - '0';
    }
    return sum;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    int sum;

    cin >> num;
    sum = sum_pv(num);

    if(num.find('0') == string::npos) {
        cout << -1;
    }
    else if(sum % 3 != 0) {
        cout << -1;
    }
    else {
        sort(num.rbegin(), num.rend());
        cout << num;
    }
}
