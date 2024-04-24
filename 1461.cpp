#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> mBooks, pBooks;

void input() {
	int tmp;
	cin >> n >> m;
	for(int i = 0; i < n ; i++) {
		cin >> tmp;
		if (tmp < 0) mBooks.push_back(tmp);
		else pBooks.push_back(tmp);
	}
	sort(mBooks.begin(), mBooks.end());
	sort(pBooks.rbegin(), pBooks.rend());
}

void sol() {
	int res = 0;
	int mtmp = 100000, ptmp = 100000;

	for (int i = 0; i < mBooks.size(); i += m) {
		res += 2 * abs(mBooks[i]);
	}

	for (int i = 0; i < pBooks.size(); i += m) {
		res += 2 * abs(pBooks[i]);
	}

	if (mBooks.size()) mtmp = mBooks[0];
	if (pBooks.size()) ptmp = -pBooks[0];

	cout << res + min(mtmp, ptmp);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}