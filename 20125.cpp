#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<string> cookie;

void input() {
	cin >> n;
	cookie.resize(n);
	for (auto& x : cookie) cin >> x;
}

void sol() {
	pair<int, int> heart;
	vector<int> answer;
	int len, idx, bottom;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (cookie[y][x] == '*') {
				heart.first = y + 1;
				heart.second = x;
				goto HEART_END;
			}
		}
	}
HEART_END:
	len = 0;
	idx = heart.second - 1;
	while(idx >= 0 && cookie[heart.first][idx--] == '*') len++;
	answer.push_back(len);

	len = 0;
	idx = heart.second + 1;
	while(idx < n && cookie[heart.first][idx++] == '*') len++;
	answer.push_back(len);

	len = 0;
	idx = heart.first + 1;
	while(idx < n && cookie[idx++][heart.second] == '*') len++;
	answer.push_back(len);
	bottom = idx - 1;

	len = 0;
	idx = bottom;
	while(idx < n && cookie[idx++][heart.second - 1] == '*') len++;
	answer.push_back(len);

	len = 0;
	idx = bottom;
	while(idx < n && cookie[idx++][heart.second + 1] == '*') len++;
	answer.push_back(len);

	cout << heart.first + 1 << ' ' << heart.second + 1 << endl;
	for(int x : answer) cout << x << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}