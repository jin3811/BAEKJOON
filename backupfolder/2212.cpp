#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, k;
vector<int> sensor;

void input() {
	cin >> n >> k;
	sensor.resize(n);
	for(int& x : sensor) cin >> x;
}

void sol() {
	// 센서-집중국을 일대일로 대응시킬수 있기 때문
	if (n <= k) {
		cout << 0;
		return;
	}
	
	int res = 0, lim = (*sensor.rbegin() - sensor[0]) / k, prev = sensor[0];
	sort(ALL(sensor));
	sensor.erase(unique(ALL(sensor)), sensor.end());

	for (int i = 1; i < n; i++) {
		if 
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}