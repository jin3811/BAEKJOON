#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

map<string, int, greater<>> scoreBoard = {{"F", 0}, {"D0", 100}, {"D+", 150},{"C0", 200},{"C+", 250},{"B0", 300},{"B+", 350},{"A0", 400},{"A+", 450}};
int n, lim, a, b, t;

void input() {
	int x, y;
	char s[3];

	scanf("%d %d.%d", &n, &x, &y);
	lim = 100 * x + y;
	for (int i = 0; i < n - 1; i++) {
		scanf(" %d %s", &x, s); 
		a += x * scoreBoard[s];
		b += x;
	}
	scanf(" %d", &t);
	b += t;
}

void sol() {
	for (auto& [x, y] : scoreBoard) {
		if ((a + t * y) / b > lim) {
			cout << x;
			return;
		}
	}
	printf("impossible");
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}