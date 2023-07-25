#include <bits/stdc++.h>
using namespace std;

int ie, is, im;

void sol() {
	int ce = 1, cs = 1, cm = 1, answer = 1;

	while (ie != ce || is != cs || im != cm) {
		ce++, cs++, cm++;
		
		if (ce > 15){
			ce = 1;
		}
		
		if (cs > 28){
			cs = 1;
		}
		
		if (cm > 19){
			cm = 1;
		}
		
		answer++;
	}
	cout << answer;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> ie >> is >> im;
	sol();
}