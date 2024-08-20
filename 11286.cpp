#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct cmp {
	bool operator()(int& a, int& b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else return abs(a) > abs(b);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, q;
	priority_queue<int, vector<int>, cmp> pq;
	
	cin >> n;
	while(n--) {
		cin >> q;
		if (q) {
			pq.push(q);
		}
		else {
			if (pq.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
	}
}