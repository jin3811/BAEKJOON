#include <iostream>
#define endl '\n'
using namespace std;

void printStar(int x, int y, int n) {
	if (y / n == 1 && x / n == 1) { // 중앙에 비는 부분
		cout << ' '; 
	} 
	else if (n == 1) { // 중앙이 아니고 n=1이면 무조건 별
		cout << '*';
	}
	else { // 위 경우가 아니면 잘라서 확인
		printStar(x % n, y % n, n/3);
	}
}

void sol(int n) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printStar(x, y, n/3);
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	sol(n);
}