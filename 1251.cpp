#include <bits/stdc++.h>
#define endl '\n'
#define ALL(X) (X).begin(), (X).end()
using namespace std;

void sol(const string& str) {
    string result, tmp, tmp1, tmp2, tmp3;
    
    result.

    for (int i = 0; i <= 100; i++) result += "z";

    for (int i = 1; i < str.length(); i++) {
        for(int j = i + 1; j < str.length(); j++) {
            tmp1 = str.substr(0, i);
            tmp2 = str.substr(i, j - i);
            tmp3 = str.substr(j, str.length() - j);

            reverse(ALL(tmp1));
            reverse(ALL(tmp2));
            reverse(ALL(tmp3));

            tmp = tmp1 + tmp2 + tmp3;
            result = min(result, tmp);
        }
    }

    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    sol(str);
}