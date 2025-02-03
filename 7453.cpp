#include<bits/stdc++.h>
#define ALL(X) X.begin(),X.end()
using namespace std;

int n;
vector<int> ab, a, b, c, d;

void input(){
	cin >> n;
	a.resize(n), b.resize(n), c.resize(n), d.resize(n), ab.resize(n*n);

	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ab[i * n + j] = a[i] + b[j];
		}
	}
	sort(ALL(ab));
}

void sol(){
	long long res = 0;
	int target;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			target = -(c[i] + d[j]);
			res += (int)(upper_bound(ALL(ab), target) - lower_bound(ALL(ab), target));
		}
	}
	cout << res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}