/**
 * boj/23309
 * 
 * 이중 원형 연결리스트 문제
 * 하지만 마냥 이중원연결리스트 문제로 풀기에는 애매하다. 역의 최대개수도 많고, 쿼리의 최대개수도 많기 때문에
 * 단순히 stl 연결리스트를 사용한다면 고유번호를 가진 역으로 이동하는데 시간을 다 쓸 것이다.
 * 
 * 그렇기에 메모리를 좀 손해보고, 2차원 배열을 통해 이중원형연결리스트 느낌을 내도록 구현한다. 이렇게 구현하면 고유번호 i가 입력되도
 * 배열의 인덱스 접근으로 처리하기 때문에 시간 복잡도는 O(1)이 된다.
 * 
 * 나머지는 쿼리 명령대로 처리하면 된다.
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q1, q2, tmp;
	string cmd;
	int subway[1000001][2] = {0};
	vector<int> v;

	cin >> n >> m;
	v.resize(n);

	for(int& x : v) cin >> x;

	for(int i = 0; i < n; i++) {
		subway[v[i]][0] = v[(i + n - 1) % n];
		subway[v[i]][1] = v[(i + 1) % n];
	}

	while(m--) {
		cin >> cmd;
		if (cmd[0] == 'B') {
			cin >> q1 >> q2;

			if (cmd[1] == 'N') {
				tmp = subway[q1][1];

				cout << tmp;

				subway[q2][0] = q1;
				subway[q2][1] = tmp;

				subway[q1][1] = q2;
				subway[tmp][0] = q2;
			}
			else if (cmd[1] == 'P') {
				tmp = subway[q1][0];

				cout << tmp;

				subway[q2][0] = tmp;
				subway[q2][1] = q1;

				subway[tmp][1] = q2;
				subway[q1][0] = q2;
			}
		}
		else {
			cin >> q1;

			if (cmd[1] == 'N') {
				tmp = subway[q1][1];

				cout << tmp;

				subway[q1][1] = subway[tmp][1];
				subway[subway[tmp][1]][0] = q1;

				subway[tmp][0] = 0;
				subway[tmp][1] = 0;
			}
			else if (cmd[1] == 'P') {
				tmp = subway[q1][0];

				cout << tmp;

				subway[q1][0] = subway[tmp][0];
				subway[subway[tmp][0]][1] = q1;

				subway[tmp][0] = 0;
				subway[tmp][1] = 0;
			}
		}
		cout << endl;
	}
}