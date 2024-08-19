#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<int> answer, bottles(3), water(3);
map<string, bool> visited;

void input() {
	for (int& b : bottles) cin >> b;
	water[2] = bottles[2];
}

string join(const vector<int>& elements, const string& delimiter = ",") {
	return accumulate(
					next(elements.begin()),
					elements.end(),
					to_string(elements[0]),
					[&](string& a, int b) {
						return a + delimiter + to_string(b);
					});
}

void backTraking() {
	string cur = join(water);
	if (visited[cur]) return;

	visited[cur] = true;
	
	if (water[0] == 0) { // 조건에 맞는 경우면 답중 하나
		answer.push_back(water[2]);
	}

	for(int i = 0; i < 3; i++) {
		if (bottles[i] - water[i] > 0) { // 물을 더 넣을 수 있는 경우 
			for (int j = 0; j < 3; j++) {
				// 자기 자신은 볼필요 없다.
				if (j == i) continue;
				// 빈컵도 볼필요 없다.
				if (water[j] == 0) continue;

				// 1. 내가 담을 수 있는 양보다 다른 컵 물이 더 많은 경우 > 그 컵에서 가져올수 있는 만큼
				// 2. 내가 담을 수 있는 양보다 다른 컵 물이 더 적은 경우 > 다가져와
				int amount = min(
					bottles[i] - water[i], // 현재 물통을 꽉채우는 양
					water[j] // 가져올 물통에 있는 양
				);

				water[i] += amount, water[j] -= amount;
				backTraking();
				water[i] -= amount, water[j] += amount;
			}
		}
	}
}

void sol() {
	backTraking();
	sort(ALL(answer));
	answer.erase(unique(ALL(answer)), answer.end());
	for (int& a : answer) cout << a << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}