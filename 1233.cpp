/**
 * solvd.ac 코드 마라톤
 * 1주차 2번
*/
#include <bits/stdc++.h>
using namespace std;

int s1, s2, s3, s;

void sol() {
	vector<int> v(s+1);
	int ans, m;
	for(int a = 1; a <= s1; a++) {
		for(int b = 1; b <= s2; b++) {
			for(int c = 1; c <= s3; c++) {
				v[a+b+c]++;
			}
		}
	}
	ans=3, m=v[3];
	for(int i = 4; i <= s; i++) {
		if (v[i] > m) {
			ans = i;
			m = v[i];
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> s1 >> s2 >> s3;
	s = s1 + s2 + s3;
	sol();
}