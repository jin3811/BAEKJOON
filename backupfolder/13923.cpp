/*
 * https://www.acmicpc.net/problem/13923
 * C++
 * 
 * 풀이전략 : 구현
 * 잘못된 유니폼을 입는 경우는 두가지로 나뉘어진다.
 * 1. n개 팀과 무관한 다른 팀의 유니폼을 입는 경우
 * 2. n개 팀에 속한 팀의 유니폼을 잘못 입고 있는 경우
 * 결과적으로는 유니폼의 개수가 n개가 아닌 두 팀을 고르고 수정하면 된다.
 * 
 * 1
 * 이 경우가 예제 입력에 나와있는 경우이다. 유니폼의 개수를 세보면 n - 1개인 팀(A)과 1개인 팀(B)이 있다.
 * B팀의 유니폼을 입고 있는 사람을 A팀 유니폼으로 바꿔주면 된다. B팀 유니폼을 입은 사람은 한명이기에 위치찾기도 편하다.
 * 그렇기에 이 경우는 쉬운 편
 * 
 * 2
 * 유니폼의 개수를 세보면 n + 1인 팀(C)과 n - 1인 팀(D)이 있다.
 * C팀의 사람을, D팀의 사람으로 바꿔주면 된다. 이때는 사람이 여러명이기 때문에 바꿔본 후, 
 * 행열에 한명씩만 앉아야 하는 제약을 지키는지 한번더 체크해야 한다.
 * 
 * 현재 여러명을 바꿔본 후를 구현하지 못함
 * => 빡구현으로 해결
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pic = pair<int, char>;
using pii = pair<int, int>;

int n;
map<char, int> m;
vector<string> cheer;

void input() {
    cin >> n;
    cheer.resize(n);
    m.clear();
    
	for (auto& str : cheer) {
		cin >> str;

		for (char c : str) {
			if (m.find(c) != m.end()) m[c]++;
			else m[c] = 1;
		}
	}
}

pii wrongCase1(const pic& wrong, const pic& correct) {
	int posR, posC;
	string target;
	target += wrong.second;

	for (int i = 0; i < n; i++) {
		auto idx = cheer[i].find(target);
		if (idx != string::npos) {
			posR = i + 1;
			posC = idx + 1;
			break;
		}
	}

	return pii(posR, posC);
}

bool validSeat() {

}

pii wrongCase2(const pic& wrong, const pic& correct) {
	int posR, posC;
	string target;
	target += wrong.second;

	bool flag = true;
	int dx[4] = {1, 0 ,-1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int y = 0; y < n && flag; y++) {
		for (int x = 0; x < n && flag; x++) {
			if (cheer[y][x] == wrong.second) {
				for (int i = 0; i < 4 && flag; i++) {
					if (y + dy[i] < 0 || y + dy[i] >= n || 
						x + dx[i] < 0 || x + dx[i] >= n) continue;
						
					if (cheer[y + dy[i]][x + dx[i]] == wrong.second) {
						posR = y + 1;
						posC = x + 1;
						flag = false;
					}
				}
			}
		}
	}

	return pii(posR, posC);
}

void sol() {
    priority_queue<pic, vector<pic>, greater<pic>> pq;

    for (auto iter : m) {
		if (iter.second != n) {
			pq.push({ iter.second, iter.first });
		}
	}

	pic wrong = pq.top(); pq.pop();
	pic correct = pq.top(); pq.pop();
	pii answer;

	if (wrong.first == 1) answer = wrongCase1(wrong, correct);
	else answer = wrongCase2(wrong, correct);

	cout << answer.first << " " << answer.second << " " << correct.second << endl;
}

void testPrint() {
	for (auto& p : m) {
		cout << p.first << " : " << p.second << endl;
	}
	cout << "----------------------------------------\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    while (!cin.eof()) {
        input();
        sol();
		// testPrint();
    }
}