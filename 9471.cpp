#include <iostream>

using namespace std;

typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test; // 전체 테스트케이스 개수
    int testCase; // 케이스 번호
    ll n; // input
    ll i; // 반복인자
    int first = 1, second = 1; // 나머지를 저장할 두 변수
    int temp; // 임시 저장
    cin >> test;

    while (test--) {
        first = 1; second = 1;
        cin >> testCase >> n;
        for(i = 2; i < n * n - 1; i++) {
            temp = first;
            first = second;
            second += temp;
            first %= n; second %= n;
            if (first == 0 && second == 1) break;
        }
        cout << testCase << ' ' << i << '\n';
    }
}