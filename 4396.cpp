#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<string> mine, user;

void input() {
	cin >> n;
	mine.resize(n); user.resize(n);
	for (auto& l : mine) cin >> l;
	for (auto& l : user) cin >> l;
}

void sol() {
	int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	bool is_end = false;


	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (user[y][x] == 'x') {
				user[y][x] = '0';
				if (mine[y][x] == '*') {
					is_end = true;
				}
			}
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (mine[y][x] == '*') {
				for (int d = 0; d < 8; d++) {
					int newX = x + dx[d], newY = y + dy[d];
					if (newX < 0 || newX >= n ||
						newY < 0 || newY >= n || 
						!isdigit(user[newY][newX])) continue;

					user[newY][newX]++;
				}
			}
		}
	}

	if (is_end) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (mine[y][x] == '*') user[y][x] = '*';
			}
		}
	}

	for(auto& l : user) {
		cout << l << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}