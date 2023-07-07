#include <bits/stdc++.h>
using namespace std;

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int money; // 지불해야할 돈
    int cnt = 0; // 거스름돈의 개수
    array<int, 6> arr = {500, 100, 50, 10, 5, 1}; // 잔돈 목록
    
    cin >> money; // 입력
    money = 1000 - money; // 거슬러 줄 돈을 계산한다.
    
    // arr[i]가 arr[i+1]의 배수이므로, 가장 큰 잔돈부터 주면 곧 가장 적은 거스름돈 개수가 된다
    for(int i = 0; i < 6; i++) { 
        cnt += money / arr[i];
        money %= arr[i];
    }
    cout << cnt; // 출력
}