#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<int> query;

void input() {
	cin >> n;
	query.resize(n);
	for(int& x : query) cin >> x;
}

void sol() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for(const int& x : query) {
		if (!x) {
			if (pq.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}