/**
 * https://suuntree.tistory.com/157
 * 
 * 1. 그냥 sqrt(n) 범위 돌면서 깡계산(11689, 4355)
 * 2. 시간 단축을 위해 폴라드로 등, 소인수분해를 먼저 한 후, 계산(13926)
 * 3. 또는 약수들을 모두 구해야하는 경우도 있다. (19577)
 * 
 * 1. 2의 경우는 오일러 피함수 내부의 탐색 범위를 수정한다.
*/

#include <bits/stdc++.h>
using namespace std;
using ul = uint64_t;

ul euler_phi(int n) {
	// n보다 작은 서로소의 개수이기 때문에 1인 경우에는 자기보다 작은 자연수가 없다.
    // n 이하의 서로소를 세는 경우에는 해당 조건을 지운다.
	// 문제 조건을 잘 확인하고, 아래 두줄의 조건을 수정한다.
    if (n == 1) return 1ULL; 
	if (n <= 3) return n - 1ULL;
	ul res = n;

	for (ul i = 2; i * i <= n; i++) {
		if (n % i) continue;
		res /= i;
		res *= (i - 1);
		while (n % i == 0) n /= i;
	}
	if (n != 1) {
		res /= n;
		res *= (n - 1);
	}

	return res;
}
