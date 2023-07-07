/*
 * 특정 디지털 숫자의 180도 회전시 숫자의 변화
 * 0, 1, 2, 5, 8 -> 그대로
 * 6, 9 -> 서로 바뀜
 * 3, 4, 7 -> 안됨
 * 
 * N이 뒤집히기 전 숫자. N은 최대 16자리
 * 
 * 1. N을 뒤집는다.
 * 2. 소수 판정
*/

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

bool is_prime(ull n) {
	if (n <= 1) return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void reverse_number(string& num) {
	// 1-1. 숫자 뒤집기
	reverse(num.begin(), num.end());

	// 1-2. 뒤집힌 숫자 수정하기
	for (char& n : num) {
		if (n == '3' || n == '4' || n == '7') {
			cout << "no";
			exit(0);
		}
		else if (n == '6') n = '9';
		else if (n == '9') n = '6';
	}
}
void sol(string& num) {
	// 1. 처음 값 저장
	if (!is_prime(stoull(num))) {
		cout << "no";
		exit(0);
	}
	// 2. 디지털 숫자 뒤집기
	reverse_number(num); 
	ull n2 = stoull(num);

	// 3. 소수 판정
	if (is_prime(n2)) cout << "yes";
	else cout << "no";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string num;
	cin >> num;
	sol(num);
}