#include <iostream>
using namespace std;
int a1, a2, a3;
int main() {
	cin.tie(0)->sync_with_stdio(false);
	while(1) {
		cin >> a1 >> a2 >> a3;
		if (!a1 && !a2 && !a3) break;
		if (a2 - a1 == a3 - a2) cout << "AP " << 2 * a3 - a2 << '\n';
		else cout << "GP " << a3 * a3 / a2 << '\n';
	}
}