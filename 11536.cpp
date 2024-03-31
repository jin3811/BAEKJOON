#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> line, incr, decr;

void input() {
	string tmp;
	cin >> n;
	line.resize(n); incr.resize(n); decr.resize(n);
	for(int i = 0 ; i < n; i++) {
		cin >> tmp;
		line[i] = incr[i] = decr[i] = tmp;
	}
}

void sol() {
	bool same = true;
	sort(incr.begin(), incr.end());
	sort(decr.rbegin(), decr.rend());


	for(int i = 0; i < n; i++) {
		same &= incr[i] == line[i];
	}
	if(same) {
		cout << "INCREASING";
		return;
	}

	same = true;
	for(int i = 0; i < n; i++) {
		same &= decr[i] == line[i];
	}
	if(same) {
		cout << "DECREASING";
		return;
	}

	cout << "NEITHER";
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}