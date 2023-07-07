#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

vector<pii> emp_score;
int n;

void input() {
	cin >> n;
	emp_score.resize(n);
	for (auto& score : emp_score)  {
		cin >> score.first >> score.second;
	}
	sort(ALL(emp_score), [](const pii& a, const pii& b){
		return a.first < b.first && a.second < b.second;
	});
}

void sol() {
	for (auto& score : emp_score) {
		cout << score.first << " " << score.second << endl;
	}
	cout << "-------------\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		sol();
	}
	// int arr[5] = {0,4,1,3,2};
	// sort(arr, arr+5, [](const int& a, const int& b){
	// 	return a < b;
	// });
	// for (int a : arr) cout << a << " ";
}