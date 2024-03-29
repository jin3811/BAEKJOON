#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	// 최선 : 고르는 족족 같은 것
	// 최악 : 모든 카드를 다 보는거, 자기자신을 두번 찍을순 없으니 1 뺌. (중심 하나 잡고 다 둘러봄)
	cout << r * c / 2 << ' ' << r * c - 1;
}