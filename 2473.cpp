#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using ll = long long;

int n;
vector<ll> v;

void input(){
	cin >> n;
	v.resize(n);
	for(ll& x : v) cin >> x;
	sort(ALL(v));
}
	
void sol(){
	vector<ll> answer;
	ll diff = INT64_MAX;

	for(int i = 0; i < n; i++){
		int l = 0, r = n-1;
		ll cur_diff;
		
		while(l < r) {
			if (l == i) {
				l++;
				continue;
			}
			if (r == i){
				r--;
				continue;
			}
			cur_diff = v[i] + v[l]+v[r];
			if (diff > abs(cur_diff)){
				diff = abs(cur_diff);
				answer = {v[l], v[r], v[i]};
			}
			if (cur_diff < 0) l++;
			else r--;
		}
	}
	sort(ALL(answer));
	for (ll& a : answer) cout << a << ' ';
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}