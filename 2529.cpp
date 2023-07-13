#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
bool used[10];
string operator_set;
vector<string> answer;

void input() {
	string temp;
	cin >> n;
	cin.ignore();
	getline(cin, temp, '\n');
	for (int i = 0; i < temp.length(); i += 2) {
		operator_set += temp[i];
	}
}

bool is_valid(char a, char b, char op) {
	if (op == '<') {
		return a < b;
	}
	else if (op == '>') {
		return a > b;
	}
}

void make_answer(int k, string num = "") {
	if (k == n + 1) {
		answer.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (used[i]) continue;

		if (k == 0 || is_valid(num[k - 1], i + '0', operator_set[k - 1])) {
			used[i] = true;
			make_answer(k + 1, num + to_string(i));
			used[i] = false;
		}
	}
}

void sol() {
	make_answer(0);
	sort(ALL(answer));
	cout << answer[answer.size() - 1] << endl << answer[0];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}