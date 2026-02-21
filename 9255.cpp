#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int target;
vector<vector<int>> sn;

void input() {
	int n, m, a, b;
	cin >> n >> m;
	sn.clear();
	sn.resize(n + 1);

	while(m--) {
		cin >> a >> b;
		sn[a].push_back(b);
		sn[b].push_back(a);
	}
	cin >> target;
}

void sol() {
	sort(ALL(sn[target]));
	sn[target].erase(unique(ALL(sn[target])), sn[target].end());
	for(int& f : sn[target]) cout << f << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc; 
	for (int i = 1; i <= tc; ++i) {
		input();
		cout << "Data Set " << i << ":" << endl;
		sol();
		cout << endl << endl;
	}
}