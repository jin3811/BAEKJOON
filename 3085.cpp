#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<string> candy;

void input() {
    cin >> n;
    candy.resize(n);
    for (auto& str : candy) {
        cin >> str;
    }
}

int candy_max() {
    int result = 1;
    int max_x, max_y;
    char idx;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            idx = candy[y][x];

            // 가로 최대 개수 세기
            max_x = 1;
            for (int i = x + 1; i < n; i++) {
                if (idx != candy[y][i]) break;

                max_x++;
            }

            // 세로 최대 개수 세기
            max_y = 1;
            for (int i = y + 1; i < n; i++) {
                if (idx != candy[i][x]) break;

                max_y++;
            }

            // 가로 세로 최대 길이 비교 후, 기존의 값과 비교
            result = max(result, max(max_x, max_y));
        }
    }

    return result;
}

void sol() {
    int answer = candy_max();
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            // 가로로 바꿔보고 체크한다
            if (x != n - 1) {
                swap(candy[y][x], candy[y][x + 1]);
                answer = max(answer, candy_max());
                swap(candy[y][x], candy[y][x + 1]);
            }
            
            // 세로로 바꿔보고 체크한다.
            if (y != n - 1) {
                swap(candy[y + 1][x], candy[y][x]);
                answer = max(answer, candy_max());
                swap(candy[y + 1][x], candy[y][x]);
            }
        }
    }

    cout << answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}