#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<vector<int> > mun;
int gom[3], gomsum;
vector<bool> visited;

void input() {
	int tmp;
	cin >> n;
	mun.resize(n, vector<int>(3));
	visited.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> mun[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		cin >> gom[i];
		gomsum += gom[i];
	}
}

int get_mungom_sum() {
	int cnt = 0;
	int rgb[3] = {0};
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			cnt++;
			for (int j = 0; j < 3; j++) {
				rgb[j] += mun[i][j];
			}
		}
	}

	for (int i = 0 ; i < 3; i++) {
		res += abs(rgb[i] / cnt - gom[i]);
	}

	return res;
}

int sol(int prev, int cnt, int r, int g, int b) {
	if (cnt > n || cnt >= 7) {
		return 1000000;
	}

	int answer = 1000;
	int temp;
	for (int i = prev + 1; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		
		if (cnt) answer = min(answer, abs((r + g + b) / cnt - gomsum));
		answer = min(answer, sol(i, cnt + 1, r + mun[i][0], g + mun[i][1], b + mun[i][2]));

		visited[i] = false;
	}

	return answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	cout << sol(-1, 0, 0, 0, 0);
}