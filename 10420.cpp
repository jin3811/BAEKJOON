#include <bits/stdc++.h>
using namespace std;

int d_day;

bool is_yun(int year) {
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	return year % 4 == 0;
}

void sol() {
	int month_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int cur_y = 2014, cur_m = 4, cur_d = 2;
	--d_day;

	while(d_day + cur_d > month_day[cur_m]) {
		d_day -= month_day[cur_m++] - cur_d;
		cur_d = 0;

		if (cur_m > 12) {
			cur_m = 1;
			++cur_y;
		}

		month_day[2] = is_yun(cur_y) ? 29 : 28;
	}

	cur_d += d_day;

	cout << cur_y << '-';
	cout << setfill('0') << setw(2) << cur_m << '-';
	cout << setfill('0') << setw(2) << cur_d;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> d_day;
	sol();
}