#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(false);
	int n;
	long long res = 0;
	vector<int> a, b, k;
	
	scanf("%d", &n);
	a.resize(n); b.resize(n); k.resize(n);
	
	for(int& x : a) scanf("%d", &x);
	for(int& x : b) scanf("%d", &x);
	for(int& x : k) {
		int t1, t2;
		scanf("%d.%d", &t1, &t2);
		x = t1*10+t2;
	}
	
	for(int i=0; i<n; i++) {
		res += max(
			a[i] * k[i] / 10 - b[i], 
			a[i] - b[i] * k[i] / 10
		);
	}
	cout << res;
	return 0;
}