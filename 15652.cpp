/**
 * boj/15652
 * 기존 N과 M 문제처럼 풀이했다.
 * 중복을 허용하기 때문에, 반복문에서 재귀를 돌 때 범위 설정에 유의했다.
 */

#include <iostream>
#define endl '\n'
using namespace std;

int n, m;

void sol(int prev, int cnt, string output) {
	if (cnt == m) {
		cout << output << endl;
		return;
	}

	for(int i = prev; i <= n; i++) {
		sol(i, cnt + 1, output + to_string(i) + " ");
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	sol(1, 0, "");
}