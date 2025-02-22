/**
 * boj/14003
 * 
 * 2568번에서 배운 lis 역추적 테크닉을 사용해야한다.
 * lis를 O(NlogN)으로 작성한 후, dp 테이블을 뒤에서부터 순회하면서 실제 lis를 구성한다.
 */

#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n;
vector<int> arr;

void input() {
	cin >> n;
	arr.resize(n);
	for(int& x : arr) cin >> x;
}

void sol() {
	vector<int> lis{-1000000001}, dp(n, 0);

	for(int i = 0; i < n; i++) {
		if(lis[lis.size() - 1] < arr[i]) {
			lis.push_back(arr[i]);
			dp[i] = lis.size() - 1;
		}
		else {
			int idx = lower_bound(ALL(lis), arr[i]) - lis.begin();
			lis[idx] = arr[i];
			dp[i] = idx;
		}
	}
	
	int len = lis.size() - 1;
	cout << len << endl;

	lis.resize(len);
	for(int i = n - 1; i >= 0 && len; i--) {
		if (dp[i] == len) {
			lis[--len] = arr[i];
		}
	}

	for(int l : lis) cout << l << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}