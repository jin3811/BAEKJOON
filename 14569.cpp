#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, m;

vector<vector<int>> lecture_table, stu_table;

void input() {
	int l;
	cin >> n;
	lecture_table.resize(n);
	for(auto& lecture : lecture_table) {
		cin >> l;
		lecture.resize(l);
		for(auto& time : lecture) {
			cin >> time;
		}
		sort(ALL(lecture));
	}

	cin >> m;
	stu_table.resize(m);
	for(auto& stu : stu_table) {
		cin >> l;
		stu.resize(l);
		for(auto& time : stu) {
			cin >> time;
		}
		sort(ALL(stu));
	}
}

void sol() {
	for(auto& stu : stu_table) {
		int ans = n;

		for(auto& lecture : lecture_table) {
			for(auto& time : lecture) {
				if (!binary_search(ALL(stu), time)) {
					ans--;
					break;
				}
			}
		}

		cout << ans << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}