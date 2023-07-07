#include <bits/stdc++.h>
using namespace std;

void solution(int n) {
    int cnt_2 = 0;
    int cnt_5 = 0;
    int temp;
    for(int i = 2; i <= n; i++) {
        temp = i;
        while(temp % 2 == 0) {
            cnt_2++;
            temp /= 2;
        }
        while(temp % 5 == 0) {
            cnt_5++;
            temp /= 5;
        }
    }
    cout << min(cnt_2, cnt_5);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    solution(n);
}