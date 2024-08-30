#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int k, m;

int dig(int base, int exp) {
	if (exp == 0) return 1;

	int tmp = dig(base, exp / 2) % 9;
	int res = (tmp * tmp) % 9;
	if (exp % 2 == 1) res = (res * base) % 9;

	// 자연수의 자릿수의 총합은 절대 0이 될 수 없다.
	// 9가 모듈러 연산으로 0이 되는 경우밖에 없다.
	return res ? res : 9; 
}

void sol() {
	int go, tx = 0, ty = 0; 
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int cycle = 0;

	// 사이클 찾기
	for(int i = 1; i < k; i++) {
		if (dig(m, i) % 9 <= 1) {
			cycle = lcm(4, i);
			break;	
		}
	}
	if (cycle && cycle < k - 1) { // 사이클이 있다면, 굳이 k번을 반복할 필요없다.
		for(int i = 1; i <= cycle; i++) { //3, 6일땐 다르게 처리해야함.
			go = dig(m, i);	
			tx += dx[i % 4] * go;
			ty += dy[i % 4] * go;
		}
		if (m % 3 != 0) { 
			tx *= (k - 1) / cycle;
			ty *= (k - 1) / cycle;
			for(int i = 1; i <= (k - 1) % cycle; i++) {
				go = dig(m, i);
				tx += dx[i % 4] * go;
				ty += dy[i % 4] * go;
			}
		}
		else {
			for(int i = 1; i <= (k - 1) % cycle; i++) {
				tx += dx[i % 4] * 9;
				ty += dy[i % 4] * 9;
			}
		}
	}
	else { // 사이클이 없거나, 사이클의 크기가 k이상이라면, k는 O(k)로 처리할수 있을 만큼, 값이 충분히 작다는 뜻이다.
		for(int i = 1; i < k; i++) {
			go = dig(m, i);
			tx += dx[i % 4] * go;
			ty += dy[i % 4] * go;
		}
	}

	// 맨 처음엔 m, k 상관없이 북쪽으로 1만큼 무조건 이동
	cout << tx << " " << ty + 1 << endl;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);
	int tcase; cin >> tcase;
	while(tcase--) {
		cin >> k >> m;
		m %= 9;
		sol();
	}
}