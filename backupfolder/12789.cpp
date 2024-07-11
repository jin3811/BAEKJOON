#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> line;

void input() {
	int x;
	cin >> n;
	line.resize(n);
	for(int& x : line) cin >> x;
}

void sol() {
	stack<int> st;
	int cur = 1;
	for (int i = 0; i < n; i++) {
		int l = line[i];
		if (cur == l) {
			cur++;
		}
		else if (!st.empty() && cur == st.top()) {
			cur++;
			st.pop();
			i--;
		}
		else {
			st.push(l);
		}
	}
	while(!st.empty()) {
		if (cur != st.top()) {
			cout << "Sad";
			return;
		}
		cur++;
		st.pop();
	}
	cout << "Nice";
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}