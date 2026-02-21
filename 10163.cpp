#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int space[1001][1001];
	int paper[100];
	int n, x, y, w, h;

	memset(space, -1, sizeof(space));
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> w >> h;
		paper[i] = w * h;

		for(int dy = y + h - 1; dy >= y; --dy) {
			for(int dx = x + w - 1; dx >= x; --dx) {
				if (space[dy][dx] != -1) {
					--paper[space[dy][dx]];
				}
				space[dy][dx] = i;
			}
		}
	}
	for(int i = 0; i < n; i++) cout << paper[i] << endl;
}