#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int int_total(const string& s) {
	int total = 0;
	for (char x : s) {
		if (isdigit(x)) {
			total += x - '0';
		}
	}
	return total;
}

bool comp(const string& a, const string& b) {
	int a_len = a.length();
	int b_len = b.length();
	int a_total = int_total(a);
	int b_total = int_total(b);

	// A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
	if (a_len != b_len) {
		return a_len < b_len;
	}
	// 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
	else if (a_total != b_total) {
		return a_total < b_total;
	}
	// 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
	else {
		return a < b;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	vector<string> v;
	int n;
	cin >> n;
	v.resize(n);
	for (auto& x : v) cin >> x;
	sort(ALL(v), comp);
	for (auto& x : v) cout << x << endl;
}