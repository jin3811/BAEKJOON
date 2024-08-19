#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using pii = pair<int,int>;

int n;
vector<int> v;

void input(){
	cin >> n;
	v.resize(n);
	for(int& x : v) cin >> x;
	sort(ALL(v));
}
	
void sol(){
	pii answer;
	int l = 0, r = n-1, diff = INT32_MAX, cur_diff;

	while(l < r) {
		cur_diff = v[l]+v[r];
		if (diff > abs(cur_diff)){
			diff = abs(cur_diff);
			answer = {v[l], v[r]};
		}
		if (cur_diff < 0) l++;
		else r--;
	}
	auto& [a,b] = answer;
	cout << a << ' ' << b;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}