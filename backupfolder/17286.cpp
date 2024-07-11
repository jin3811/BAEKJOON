#include <bits/stdc++.h>
#define ALL(X) X.begin()+1, X.end()
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	vector<pair<int, int>> points(4);
	double answer = 100000, temp;
	for (auto& [x, y] : points) cin >> x >> y;
	sort(ALL(points));
	do {
		temp = 0.;
		for (int i = 1; i < 4; i++) {
			auto& [cx, cy] = points[i - 1];
			auto& [nx, ny] = points[i];
			int dx = cx - nx, dy = cy - ny;
			temp += sqrt(dx*dx + dy*dy);
		}
		answer = min(temp, answer);
	} while(next_permutation(ALL(points)));
	cout << (int)answer;
}