#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1000000007
using namespace std;
using ull = uint64_t;

int l, u;

char checkWinner() {
	bool winH = false;

	// 단어의 길이가 1, 2인 경우 단어의 개수는 홀수개이다.
	// 3 이상부턴 모두 짝수개이기 때문에 사실상 여기서 결정난다.
	for (int i = 1; i <= 2; i++) {
		if (l <= i && i <= u) {
			winH = !winH;
		}
	}

	return (winH ? 'H' : 'A');
}

// 최대 50만번 제곱하기 때문에 빠른 제곱을 해야한다.
ull fastSquere(int a, int b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else {
		ull temp = fastSquere(a, b / 2) % MOD;
		if (b % 2 == 1) {
			return (((temp * temp) % MOD) * a) % MOD; // << 여기서 모듈러 연산 주의
		}
		else {
			return (temp * temp) % MOD;
		}
	}
}

ull countPal() {
	ull res = 0;
	ull temp;

	for (int i = l; i <= u; i++) {
		if (i <= 2) {
			res++;
		}
		else {
			temp = fastSquere(26, (i - 1) / 2) % MOD; // 맨앞, 맨뒤글자는 한번 부르면 정해지기 때문에 셀 필요가 없다. 중간만 세면 됨
			res = ((res % MOD) + temp) % MOD;
		}
	}
	return res;
}

void sol() {
	cout << checkWinner() << endl; // 단어 개수가 MOD 연산을 하기 때문에 먼저 체크
	cout << countPal() << endl; // 단어를 센다
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> l >> u;
	sol();
}