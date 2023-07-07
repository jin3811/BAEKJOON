#include <bits/stdc++.h>
using namespace std;

int N;
int* T; // Ti
int* P; // Pi
int* dp; // dp 식

void input(){
    cin >> N;
    T = new int[N + 1];
    P = new int[N + 1];
    dp = new int[N + 1];
    fill(dp, dp + N + 1, 0); // 초기화
    for(int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
}

void solution(){
    int max_pay = 0; // 최댓값을 저장하는 변수
    for(int i = 0; i <= N; i++) {
        dp[i] = max(max_pay, dp[i]);
        // 잘못된 메모리 참조를 하지 않기 위한 조건
        if (T[i] + i <= N) {
            dp[T[i] + i] = max(dp[T[i] + i], P[i] + dp[i]);
        }
        max_pay = max(max_pay, dp[i]);
    }
    cout << max_pay;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
}

/* dfs(?)
#include <bits/stdc++.h>
using namespace std;

int N;
int* T; // Ti
int* P; // Pi
int max_pay = 0;

void input(){
    cin >> N;
    T = new int[N + 1];
    P = new int[N + 1];
    for(int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
}

void solution(int x, int sum){
    if (x > N) return;

    max_pay = max(max_pay, sum);
    for(int i = x; i < N; i++) {
        solution(T[i] + i, sum + P[i]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution(0, 0);
    cout << max_pay;
}
*/