#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<int> a;
int n;

void input() {
	cin >> n;
	a.resize(n);
	for (int& x : a) cin >> x;
}

void sol() {
	uint64_t ev_tmp = 0, ev_dest = 0;
	uint64_t od_tmp = 0, od_dest = 0;
	
	
	for (int i = 0; i < n; i++) {
		// 짝수를 왼쪽으로 몰아버리는 경우
		if (a[i] % 2 == 0) {
			ev_tmp += i - ev_dest++;
		}
		// 홀수를 왼쪽으로 몰아버리는 경우
		else {
			od_tmp += i - od_dest++;
		}
	}
	cout << min(ev_tmp, od_tmp);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}