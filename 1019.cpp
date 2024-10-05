#include <bits/stdc++.h>
using namespace std;

int n;
int page[10];

void count_page(int w) {
	if (n <= 0) return;

	int q = n / 10, r = n % 10;

	// 등장하는 1의 자리의 개수를 저장
	for(int i = 1; i < 10; i++) {
		page[i] += q * w;
	}

	// 마지막 1~r만큼 남는다. 해당 케이스 카운트
	for(int i = 1; i <= r; i++) {
		page[i] += w;
	}

	// 0은 q번 등장한다.
	page[0] += q * w;

	// 마지막으로 등장하는 10의 자리는 10개가 되지 않기에 전처리
	if (q) {
		int tmp = q;
		while(tmp){
			page[tmp % 10] += (r + 1) * w;
			tmp /= 10;
		}
	}
	n = q - 1;
	count_page(w * 10);
}

void sol() {
	count_page(1);
	for(int& x : page) cout << x << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	sol();
}