/**
 * https://www.acmicpc.net/problem/4108
 * C++
 * 
 * 풀이전략 : 구현
 * 필자의 경우는 지뢰를 기준으로 풀이했다.
 * 지뢰 주변의 땅에 1씩 더해주는 연산을 모든 지뢰에 동일하게 진행하면 된다.
 * 만약 땅을 기준으로 한다면, 각 땅에서 주변을 둘러본 후, 지뢰를 세면 된다.
*/

#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int r, c;
vector<string> field;

void input_field() {
    field.resize(r);
    
    for (int y = 0; y < r; y++) {
        cin >> field[y];
        for(int x = 0; x < c; x++) {
            if (field[y][x] == '.') field[y][x] = '0';
        }
    }
}

void sol() {
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (field[y][x] == '*') {
                for (int d = 0; d < 8; d++) {
                    int new_x = x + dx[d];
                    int new_y = y + dy[d];

                    if (new_x < 0 || new_x >= c ||
                        new_y < 0 || new_y >= r || field[new_y][new_x] == '*') continue;

                    field[new_y][new_x]++;
                }
            }
        }
    }

    for (auto& line : field) cout << line << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    while(1)  {
        cin >> r >> c;
        if (r == 0 && c == 0) break;

        input_field();
        sol();
    }
}