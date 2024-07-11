#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n;
vector<int> v;

void input() {
	cin >> n;
	v.resize(n);
	for(int& x : v) cin >> x;
}

bool checker(int& f1, int& f2, int tang) {
	// 1. 초기상황 : 
	bool res;
	if (f1 == -1) {
		f1 = tang;
		res = true;
	}
	else if (f2 == -1) {
		f2 = tang;
		res = true;
	}

	
	return res;
}

void sol() {
	int f1 = v[0], f2= -1;
	int l = 0, r = 1;

	while (l <= r) {
		checker(f1, f2, );
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}