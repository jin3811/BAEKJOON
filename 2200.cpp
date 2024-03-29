/**
 * https://www.acmicpc.net/problem/2200.cpp
 * C++
 * 
 * 풀이 전략 : 구현
 * 
 * 해당 문제를 쉽게 만들어 주는 것은 문제의 마지막 조건이다.
 * "추가 메모리가 없기 때문에 계산을 할 때에 계산 직전에 계산기에 저장되어 있던 값에 계산을 한다."
 * 
 * 해당 조건을 통해, 우리가 곱하기연산을 진행하면 이전 항에도 x가 곱해진다.
 * 이를 사용하면 x^3 + x + 11은 문제에서 말한대로 x * x * x + x + 1 1 = 로 해결할 수 있지만,
 * x * x + 1 * x + 1 1 = 로도 입력할 수 있다. 
 * 이런 방식으로 입력하면, 계수가 0이어도 처리가 가능해진다.
 * 또한, 최고차항의 계수는 무조건 1이고, 등호는 어떤 식을 입력해도 입력해야 하기에, 미리 처리하여 구현의 편의를 올렸다.
 * 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, input, res=2;

	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> input;
		if (!i) continue; // 처음 계수는 이미 처리함
		if (i != n) res += 2; // 상수항이 아니면 x를 곱해야함.
		if (input) { // 상수 or 계수 처리
			++res; // 덧셈기호
			while(input) { // 숫자길이
				++res;
				input /= 10;
			}
		} // res += 1 + (int)log10(input*10); // 덧셈기호, 숫자길이(로그값 조정 위해 10 곱해야 함. log10(9) = 0),
	}
	cout << res;
}