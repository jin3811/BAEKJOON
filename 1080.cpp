#include <bits/stdc++.h>
using namespace std;
using vs = vector<string>;

void change(vs& v, int x, int y) {
    for(int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            v[i][j] = v[i][j] == '1' ? '0' : '1';
        }
    }
}

bool same(const vs& input, const vs& target, int x, int y) {
    for(int i = 0; i < y; i++) {
        if (input[i] != target[i]) return false;
    }
    return true;
}

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, y; // 행렬의 크기
    int cnt = 0; // 연산 횟수
    string temp; // 행렬 입력을 위한 
    vs input, target;

    cin >> y >> x;

    input.resize(y); target.resize(y); // 미리 할당

    for(auto& v : input) cin >> v;
    for(auto& v : target) cin >> v;

    /*
     * 어디서부터 연산을 수행하던 이 연산은 교환법칙이 성립하기 때문에, 
       최적의 위치를 찾고 찾아 연산하는 것은 결국 맨 처음위치부터 연산을 수행하는 것과 같다.     
     * 또한 같은 위치에서의 중복연산은 최소값이 되지 않을 뿐더러, 최소값이 되어야 한다고 해도, 하나마나인 행동이다.
     * 현 위치로부터 3 x 3안의 구역에서 연산하기 때문에 0 ~ x - 3, 0 ~ y - 3의 범위만을 탐색한다.
    */
    for(int i = 0; i < y - 2; i++) {
        for(int j = 0; j < x - 2; j++) {
            if (input[i][j] != target[i][j]){
                cnt++;
                change(input, j, i);
            }
        }
    }
    cout << (same(input, target, x, y) ? cnt : -1);
}