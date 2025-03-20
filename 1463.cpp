// sol1
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	priority_queue<pair<int,int>> pq;
	bool visit[n] = {0, };

	pq.push({0, -n});

	while(!pq.empty()) {
		auto [cnt, cur] = pq.top(); pq.pop();

		if (-cur == 1) {
			cout << -cnt;
			break;
		}

		if (-cur % 3 == 0 && !visit[-cur/3]) {
			pq.push({cnt-1, cur/3});
			visit[-cur/3] = true;
		}
		if (-cur % 2 == 0 && !visit[-cur/2]) {
			pq.push({cnt-1, cur/2});
			visit[-cur/2] = true;
		}
		if (!visit[-cur-1]) {
			pq.push({cnt-1, cur+1});
			visit[-cur-1] = true;
		}
	}
}

// sol2
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int dp[n + 1] = {0, };

	memset(dp, 1, sizeof(int) * n);

	for(int i = n; i > 0; --i) {
		if (i % 3 == 0) dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		if (i % 2 == 0) dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}

	cout << dp[1];
}