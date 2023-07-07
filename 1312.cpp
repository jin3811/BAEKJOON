#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int a, b, n;

void input() {
	cin >> a >> b >> n;
}

void sol() {
	int res;
	int ans;
	// 첫번째 나눗셈 연산은 몫에 관한 연산이기 때문에 한번 더 연산을 해줘야 한다.
	for (int i = 0; i <= n; i++) {
		ans = a / b;
		res = a % b;
		a = res * 10;
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}