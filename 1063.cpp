#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string move_piece(string p, string& dir) {
	if ((p[0] == 'A' && dir[0] == 'L') ||
		(p[0] == 'H' && dir[0] == 'R') ||
		(p[1] == '1' && dir.find('B') != string::npos) ||
		(p[1] == '8' && dir.find('T') != string::npos)) return p;
	for(char d : dir) {
		if (d == 'R') ++p[0];
		else if (d == 'L') --p[0];
		else if (d == 'B') --p[1];
		else if (d == 'T') ++p[1];
	}
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string king, stone, dir, tmp;

	cin >> king >> stone >> n;

	while(n--) {
		cin >> dir;
		tmp = move_piece(king, dir); // 이동 시도
		if (stone == tmp) { // 이동하려는 곳에 돌이 있다면
			// 돌 옮기기 시도
			if (stone != move_piece(stone, dir)) { // 돌 이동이 가능하면
				stone = move_piece(stone, dir);
				king = tmp;
			}
		}
		else { // 이동하려는 곳에 돌이 없으면
			king = tmp; // 그냥 이동
		}
	}
	cout << king << endl << stone;
}