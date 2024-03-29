#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, a, b, x;
	cin >> n;
	while(n--) {
		cin >> a >> b >> x;
		cout << (a * (x - 1) + b) << endl;
	}
}