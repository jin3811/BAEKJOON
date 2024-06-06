#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pss = pair<string, string>;

int n;
vector<pss> ment;

void input() {
	cin >> n;
	ment.resize(n);
	for(auto&[o, i] : ment) cin >> o >> i;
}

void sol() {
	sort(ALL(ment), [](const pss& p1, const pss& p2) {
		auto& [p1o, p1i] = p1;
		auto& [p2o, p2i] = p2;
		return p1o != p2o ? p1o < p2o : p1i > p2i;
	});
   for(auto&[o, i] : ment) {
		cout << o << ' ' << i << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}