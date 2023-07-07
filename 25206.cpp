#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

double grade_total, score_total;

void input() {
	map<string, double> table = {
		{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, 
		{"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0},
		{"D+", 1.5}, {"D0", 1.0}, {"F", 0},
	};
	string name, score;
	double grade;
	int tc = 20;
	
	while(tc--) {
		cin >> name >> grade >> score;
		if (score[0] != 'P') {
			grade_total += grade;
			score_total += grade * table[score];
		}
		cin.ignore();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	cout << score_total / grade_total;
}