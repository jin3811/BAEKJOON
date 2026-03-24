#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int l, r, ml = 0, mr = 0;
	cin >> l >> r;

	while (l != 1 && r != 1) {
		if (l < r) {
			r -= l;
			++mr;
		}
		else {
			l -= r;
			++ml;
		}
	}

	if (r == 1) ml += l - 1;
	else mr += r - 1;

	cout << ml << ' ' << mr;
}