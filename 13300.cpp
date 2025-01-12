#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int k, students[2][7];

void input() {
	int total, gender, grade;
	cin >> total >> k;
	for(int i = 0; i < total; i++) {
		cin >> gender >> grade;
		++students[gender][grade];
	}
}

void sol() {
	int ans = 0;
	for(int gender = 0; gender <= 1; ++gender){
		for(int grade = 1; grade <= 6; ++grade) {
			int& stu = students[gender][grade];
			ans += stu / k;
			ans += (stu % k > 0);
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}