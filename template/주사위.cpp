/**
 * 주사위를 굴리거나 하는 문제에 대한 주사위 구현체
 * https://www.acmicpc.net/problem/23288
 * https://www.acmicpc.net/problem/14499
 */
#include <bits/stdc++.h>
using namespace std;

struct Dice {
	int number[4][3] = {
		{-1, 2, -1}, //    북
		{ 4, 1, 3 }, // 서 상 동
		{-1, 5, -1}, //    남 
		{-1, 6, -1}, //    하
	};

	int get_under_num() {
		return number[3][1];
	}

	void role_dice(char dir) {
		int tail;
		if (dir == 'n') { // 북쪽 회전
			for (int i = 1; i < 4; i++) {
				swap(number[i - 1][1], number[i][1]);
			}
		}
		else if (dir == 's') { // 남쪽 회전
			for (int i = 3; i > 0; i--) {
				swap(number[i][1], number[i - 1][1]);
			}
		}
		else if (dir == 'e') { // 동쪽 회전
			rotate(number[1], number[1] + 2, number[1] + 3);
			swap(number[1][0], number[3][1]);
		}
		else if (dir == 'w') { // 서쪽 회전
			rotate(number[1], number[1] + 1, number[1] + 3);
			swap(number[1][2], number[3][1]);
		}
		else assert(false);
	}
	
	// void show_dice() {
	// 	for(int y = 0; y < 4; y++) {
	// 		for(int x = 0; x < 3; x++) {
	// 			if (number[y][x] == -1) cout << "  ";
	// 			else cout << number[y][x] << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// }
};