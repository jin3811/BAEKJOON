#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, m, stu, stuScore,ansStu = 0, ansScore = -1;
	char prob;
	vector<int> score;

	cin >> n >> m;
	score.resize(n);
	for(int& x : score) cin >> x;

	while(m--) {
		stuScore = 0;
		cin >> stu;
		for(int i = 0; i < n; i++) {
			cin >> prob;
			if (prob == 'O') stuScore += score[i];
		}
		if (ansScore < stuScore || (ansScore == stuScore && ansStu > stu)) {
			ansStu = stu;
			ansScore = stuScore;
		}
	}

	cout << ansStu << ' ' << ansScore;
}