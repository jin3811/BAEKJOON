#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define LIM 500000
using namespace std;

int target, break_cnt;
bool breakBtn[10]; // 부서짐 -> true

void input() {
	int n;
	cin >> target >> break_cnt;
	for (int i = 0; i < break_cnt; i++) {
		cin >> n;
		breakBtn[n] = true;
	}
}

bool isBreakNum(int n) { // 부서진 버튼이 포함되어있는지.
	do {
		if (breakBtn[n % 10]) return true;
		n /= 10;
	} while(n);
	return false;
}

int numLength(int n) { // 숫자 길이
	return to_string(n).length();
}

void sol() {
	int move_cnt = -1, just_move = -1;
	vector<int> btnList;
	btnList.push_back(100); // 현재 위치한 채널은 부서진 버튼에 상관 없이 가능함.

	for(int i = 0; i <= LIM * 2; i++) {
		if (!isBreakNum(i)) btnList.push_back(i);
	}
	sort(ALL(btnList), [](const int& a, const int& b){
		int da = abs(target - a), db = abs(target - b); // target과의 거리
		if (da != db) return da < db; // 다르면 더 가까운쪽
		else return numLength(a) < numLength(b); // 같으면 더 길이가 짧은 쪽
	});
	
	move_cnt = abs(btnList[0] - target) + numLength(btnList[0]); // 업다운 누르는 횟수 + 숫자버튼 누르는 횟수
	just_move = abs(target - 100); // 단순히 updown키로 이동하는게 더 빠를수도 있다.
	cout << min(just_move, move_cnt);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}