#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;

void input() {
	cin >> n;
	nums.resize(n);
	for(int& x : nums) cin >> x;
}

void sol() {
	vector<int> nge(n, -1);
	stack<pair<int, int>> st;

	for(int i = 0; i < nums.size(); i++) {
		while (!st.empty() && st.top().first < nums[i]) {
			nge[st.top().second] = nums[i];
			st.pop();
		}
		st.push({nums[i], i});
	}
	for(int x : nge) cout << x << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}