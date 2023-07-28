#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define CHECKED '-'
using namespace std;

int n, m;
vector<string> v;

void input() {
    cin >> n >> m;
    v.resize(m);
    for(auto& str : v) cin >> str;
}

int bfs(int x, int y) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    const char crit = v[y][x];
    int cnt = 0;
    queue<pair<int, int>> q;

    v[y][x] = CHECKED;
    cnt++;
    q.push({x, y});

    while(!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x < 0 || next_x >= n ||
                next_y < 0 || next_y >= m ||
                v[next_y][next_x] != crit) {
                continue;
            }
            
            v[next_y][next_x] = CHECKED;
            cnt++;
            q.push({next_x, next_y});
        }
    }

    return cnt;
}

void sol() {
    int power_w = 0;
    int power_b = 0;
    int temp;
    char crit;

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if(v[y][x] != CHECKED) {
                crit = v[y][x];
                temp = bfs(x, y);
                
                if (crit == 'W') {
                    power_w += temp * temp;
                }
                else {
                    power_b += temp * temp;
                }
            }
        }
    }

    cout << power_w << " " << power_b;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}