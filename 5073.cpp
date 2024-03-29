#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<int> line;
array<string, 4> answer = {"Invalid", "Scalene", "Isosceles", "Equilateral"};

void sol() {
	sort(ALL(line));
	if (line[0] + line[1] <= line[2]) {
		cout << answer[0] << endl;
		return;
	}
	line.erase(unique(ALL(line)), line.end());   
	cout << answer[4 - line.size()] << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	while (1) {
		line.resize(3);
		for(int i = 0; i < 3; i++) cin >> line[i];
		if(!line[0]) break;
		sol();
	}
}