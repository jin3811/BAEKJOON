/**
* boj/28702
 * 직관적으로 15주기로 패턴이 반복됨을 알 수 있음. 1~15까지의 fizzbuzz 패턴이 16~30과 동일함.
 * 또한 fizz, buzz, fizzbuzz는 각각 연속 3번이 모두 나올수 없다. fizz, bizz, fizzbuzz, 또는 fizz, fizzbuzz, bizz 이런식의 패턴
 * 이는 입력에 무조건 숫자가 들어와야만 한다는 뜻이기 때문에 입력된 숫자를 기반으로 다음 숫자를 알 수 있다.
 * 이후 적절하게 fizzbuzz 규칙에 맞게 변환하면 끝
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string fb[3]; 

void fizzbuzz(int n) {
	if (n % 3 && n % 5) {
		cout << n;
	}
	else {
		if (n % 3 == 0) {
			cout << "Fizz";
		}
		if (n % 5 == 0) {
			cout << "Buzz";
		}
	}
	cout << endl;
}

void sol() {
	for(int i = 0; i < 3; i++) {
		if (isdigit(fb[i][0])) {
			int ans = stoi(fb[i]) + 3 - i;
			fizzbuzz(ans);
			break;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	for(string& x : fb) cin >> x;
	sol();
}