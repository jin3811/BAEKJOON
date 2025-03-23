#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pii = pair<int,int>;

void print(vector<pii>& v) {
	if (v.size() == 0) cout << "sleep";
	else for(auto[_, a] : v) cout << a << ' '; 
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, n, t;
	string cmd;
	cin >> N >> M;

	vector<pii> postit;

	while(N--) {
		cin >> cmd;
		if (cmd[0] == 'o') {
			cin >> n >> t;
			postit.push_back({t, n});
		}
		else if (cmd[0] == 's') {
			sort(ALL(postit));
		}
		else {
			cin >> n;
			for(auto i = postit.begin(); i != postit.end(); ++i) {
				if (i->second == n) {
					postit.erase(i);
					break;
				}
			}
		}
		print(postit);
	}
}