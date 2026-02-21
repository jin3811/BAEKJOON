#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, ans=2;
	cin >> n;
	while(n--) ans = 2*ans - 1;
    cout << ans*ans;
}