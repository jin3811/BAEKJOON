#include <bits/stdc++.h>
using namespace std;
#define ALL(it) it.begin(), it.end()

string bin1, bin2, result;

void bin_plus() {
    reverse(ALL(bin1));
    reverse(ALL(bin2));
    result.clear();
    if (bin1.length() < bin2.length()) swap(bin1, bin2); // 더 긴 숫자가 bin1

    int flag = 0;
    int i = 0;
    int temp;

    for(; i < bin2.length(); i++) {
        temp = (bin1[i] - '0') + (bin2[i] - '0') + flag;
        // 2가 넘어가면 다음자리로 1을 넘겨줘야 한다.
        if(temp >= 2) flag = 1;
        else flag = 0;
        result += (temp % 2) + '0';
    }

    for(; i < bin1.length(); i++) {
        temp = (bin1[i] - '0') + flag;
        // 이 반복문에서는 temp가 2가 최대이다.
        if(temp == 2) flag = 1;
        else flag = 0;
        result += (temp % 2) + '0';
    }

    if(flag == 1) result += '1'; // 마지막 1이 남아있다면 붙여준다
    reverse(ALL(result));
    while(*result.begin() == '0' && result.length() > 1) { // delete leading zero
        result.erase(result.begin(), result.begin() + 1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcase;

    cin >> tcase;
    while(tcase--) {
        cin >> bin1 >> bin2;
        bin_plus();
        cout << result << '\n';
    }
}