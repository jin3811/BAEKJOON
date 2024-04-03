#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n, res=0;
	vector<pii> p;
	bool flag=false;

	cin >> n;
	p.resize(n);
	for(auto& [s,e]:p) cin >> s >> e;
	sort(p.begin(), p.end());

	auto& [ls,le]=p[0];
	for (int i=1; i<n; i++){
		const auto& [cs,ce] = p[i];

		if(cs<=le) {
			le = max(le, ce);
		}
		else {
			res += le-ls;
			ls = cs, le=ce;
		}
	}
	res += le-ls;
	cout << res;
}