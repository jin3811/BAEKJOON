// 6800
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

map<string, string> wordCode; // 알파벳 코드 저장
string hufCode; // 디코딩할 허프만코드
array<string, (int)(2e6)> wordTree; // 트리 구성

void input() {
    int n;

    cin >> n;
    string word, code;

    for(int i = 0; i < n; i++) {
        cin >> word >> code;
        wordCode.insert({word, code}); // 알파벳, 코드 저장
    }

    cin >> hufCode;
}

void setTree() {
    wordTree.fill("-"); // 트리 초기화. - 는 비어있다는 뜻
    int idx;

    for (auto iter = wordCode.begin(); iter != wordCode.end(); iter++) {
        idx = 1; // 시작 위치
        for(auto x : iter->second) {
            if (x == '0') idx *= 2; // 0이면 왼쪽
            else idx = idx * 2 + 1; // 1이면 오른쪽
        }
        wordTree[idx] = iter->first; // 구한 인덱스에 문자 삽입
    }
}

void sol() {
    setTree(); // 허프만 트리 구성
    
    string answer;
    int idx = 1;

    for (int i = 0; i < hufCode.length(); i++) {
        if (hufCode[i] == '0') idx *= 2;
        else idx = idx * 2 + 1;

        if (wordTree[idx] != "-") { // 만약 해당 노드에 값이 존재하면
            answer += wordTree[idx]; // 알파벳 기록하고
            idx = 1; // 루트로 돌아간다.
        }
    }
    cout << answer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}