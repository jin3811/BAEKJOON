/** 
 * boj/17253
 * 
 * 그리디하게 풀 수 있는 문제였다.
 * 입력받은 n보다 작으면서 가장 근접한 3의 거듭제곱 a를 찾으며 n에서 a를 뺀 후 재귀함수와 지수(3을 몇번 제곱했는지)에서 1을 빼준 값을
 * 같이 재귀함수에 넘겨준다. 같은 3의 거듭제곱은 쓸 수 없기 때문이다.
 * 
 * 이 문제는 자칫하면 TLE를 받을 수 있다. n에 근접한 a를 찾으면 거기서 더 반복문을 돌며 지수를 줄일 필요가 없다.
 * 만약 a보다 더 작은 a/3을 n에서 빼봤자 a/3 이하의 값으로 (n - a/3)을 만들수 없다. 이를 수행하지 않으면 팩토리얼 시간복잡도에 근접한다.
 * 3^40 > 2^63 > 3^39이기 때문에 최대 39!의 시행 횟수를 가진다.
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