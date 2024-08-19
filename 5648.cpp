#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	int tc;
	cin >> tc;
	vector<long long> v;
	string x;

	while (tc--) {
		cin >> x;
		reverse(ALL(x));
		v.push_back(stoll(x));
	}
	sort(ALL(v));
	for(long long x : v) cout << x << '\n';
	cout << "개수 : " << v.size();
}