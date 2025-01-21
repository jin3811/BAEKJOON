#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, c, p, ans = 0;
	map<int, int> cow;

	cin >> n;

	while(n--) {
		cin >> c >> p;
		if (cow.find(c) != cow.end() && cow[c] != p){
			ans++;
			cow[c] = p;
		}
		else {
			cow.insert({c, p});
		}
	}
	cout << ans;
}