/**
 * boj/1715
 * 
 * 15903번 문제와 거의 같은 문제. 가장 작은값부터 더해나가면 된다.
 */
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

void input() {
	int n, data;
	cin >> n;

	while(n--) {
		cin >> data;
		pq.push(-data);
	}
}

void sol() {
	int a, b, ans = 0;
	while(pq.size() > 1) {
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		ans -= a + b;
		pq.push(a + b);
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}