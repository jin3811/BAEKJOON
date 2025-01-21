/**
 * boj/17252
 * 
 * 이 문제에서 한발짝 더 나아간 17253번을 미리 풀었기 때문에 해당 문제는 바로 AC를 받았다.
 * 해당 문제의 입력 숫자의 최댓값은 2^31이지만 17253번은 2^63이다.
 */
#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;

ll my_pow(ll a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	ll t = my_pow(a, b / 2);
	if (b % 2 == 1) return t * t * a;
	else return t * t;
}

bool sol(ll num, int exp) {
	if (num == 0) return true;
	if (num < 0) return false;
	ll val;
	for(; exp >= 0; exp--) {
		val = my_pow(3, exp);
		
		if (num < val) {
			continue;
		}
		return sol(num - val, exp - 1);
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;

	cin >> n;
	cout << (n != 0 && sol(n, 39) ? "YES" : "NO");
}