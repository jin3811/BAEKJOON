/**
 * 1. 숫자를 최대한 많은 2의 거듭제곱의 합으로 바꾸기 -> 비트로 바꾸면 된다
 * 2. 하나씩 제거해보면서 제일 큰 경우 찾기 -> 답 없음. 그냥 브루트포스
 * 
 * 각 2의 제곱이 등장하는 횟수 전체저장
 * 각 숫자의 거듭제곱 저장
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ai;
map<int, int> num_count;

int mypow(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	else {
		int temp = mypow(a, b / 2);
		if (b % 2 == 1) return temp * temp * a;
		else return temp * temp;
	}
}

void input() {
	cin >> n;
	ai.resize(n);
	for(int& x : ai) cin >> x;
}

int sum_elem() {
	int sum = 0;
	for (auto& x : num_count) {
		if (x.second % 2 == 1) {
			sum += x.first;
		}
	}
	return sum;
}

void sol() {
	int res = 0, temp;
	bitset<22> a;

	// 표현법 변경시, 거듭제곱항의 개수
	for (int x : ai) {
		a = x;
		for (int i = 0; i < 22; i++) {
			if (a[i]) num_count[mypow(2, i)]++;
		}
	}

	// 제거 안해보고 세본다.
	res = max(res, sum_elem());

	// 제거해보고 세본다.
	for (int x : ai) {
		temp = 0;
		a = x;

		// 제거해본다.
		for (int i = 0; i < 22; i++) {
			if (a[i]) num_count[mypow(2, i)]--;
		}

		// 센다.
		res = max(res, sum_elem());

		// 원상복구
		for (int i = 0; i < 22; i++) {
			if (a[i]) num_count[mypow(2, i)]++;
		}
	}
	cout << res << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}