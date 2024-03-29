#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, qn, qurey, var;
vector<vector<int>> board;

void input() {
	cin >> n;
	board.resize(n, vector<int>(n));
	for (auto& col : board) {
		for (int& x : col) {
			cin >> x;
		}
	}
	cin >> qn;
}

void sol(int qurey, int col=-1) {
	if (qurey == 1) {
		rotate(board[col - 1].rbegin(), board[col - 1].rbegin() + 1, board[col-1].rend());
	}
	else if (qurey == 2) {
		vector<vector<int>> origin(board);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[j][n - i - 1] = origin[i][j];
			}
		}
	}
}

void print() {
	for (auto& col : board) {
		for (int x : col) {
			cout << x << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	while (qn--) {
		cin >> qurey;
		if (qurey == 1) {
			cin >> var;
			sol(qurey, var);
		}
		else {
			sol(qurey);
		}
	}
	print();
}