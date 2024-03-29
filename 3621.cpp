#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, d;
map<int, int> jok;

void input() {
	cin >> n >> d;
	int tmp;
	while(n--) {
		cin >> tmp;
		jok[tmp]++;
	}
}

void sol() {
	int res = 0;
	for (auto [x, num] : jok) {
		if (num > d) {
			while (num > d) {
				res += num / d;
				num = num / d + num % d;
			}
		}
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}