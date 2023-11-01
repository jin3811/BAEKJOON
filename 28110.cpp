/*
 * https://www.acmicpc.net/problem/28110
 * C++
 * 풀이 전략 : 그리디
 * 
 * 기존 문제들과의 난이도 차이의 최솟값이 가장 커지도록 문제를 낼 것
 * -> 해석이 많이 어려웠지만, 결과적으로 한 문제의 난이도가 주어졌고, 난이도를 오름차순 정렬했을때, 
 *    인접한 두 문제의 난이도 차이중의 최솟값을 의미한다.
 *    이런 최솟값이 제일 크도록 하는 문제의 난이도를 찾아야 한다
 * 그리디적으로 생각해보면, 두 난이도 a, b (a + 1 < b) 사이에서 나올 수 있는 해당 조건을 만족하는 정수 값은 (a + b) / 2값이 된다.
 * 그래야 제일 큰 최솟값이 나온다. 만약 a나 b에 치우쳐져있다면, 난이도 차이가 작아질 것이니 말이다.
 * 해당하는 값들을 모두 구하고, 이 값을 바탕으로 답을 구하면 된다.
*/

#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<int> problem;

void input() {
    cin >> n;
    problem.resize(n);
    for (int& i : problem) cin >> i;
    sort(ALL(problem));
}

// 구간 [n1, n2]에 속하는 target의 난이도 차이
int calDiff(int n1, int n2, int target) {
    return min(target - n1, n2 - target);
}

void sol() {
    int n1, n2; // 인접한 두 난이도
    int answer = -1, diff = -1; // 모든 난이도가 연속적인 값이라면 -1을 반환해야하기에 초기값을 -1로 잡는다
    int tempAns, tempDiff; // 중간중간 답과 차이를 저장할 변수

    for (int i = 0; i < n - 1; i++) {
        // 인접한 두 문제를 가져온다.
        n1 = problem[i];
        n2 = problem[i + 1];

        // 연속된 값이면 pass
        if (n2 - n1 == 1) continue;

        // [n1, n2] 구간에서 조건에 부합하는 값 생성
        tempAns = (n1 + n2) / 2;
        tempDiff = calDiff(n1, n2, tempAns);

        // 해당 차이가 기존의 값보다 크면 갱신
        if (diff < tempDiff) {
            answer = tempAns;
            diff = tempDiff;
        }
    }

    cout << answer;
}

int main() {
    // fast io
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}