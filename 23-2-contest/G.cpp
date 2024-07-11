#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using tii = tuple<int, int, int>;

int bugi_pos;
int n, m;
vector<vector<int>> hole;

void input() {
    cin >>n >> m;
    hole.resize(n);
    for (auto& row : hole) row.resize(m);
    bugi_pos = m / 2;
}

int dist(int x, int y) {
    return abs(x - bugi_pos) + y + 5;
}

bool comp(const tii& a, const tii& b) {
    auto [ad, ax, ay] = a;
    auto [bd, bx, by] = b;

    if (ad != bd) return ad < bd;
    else {
        return ax < bx;
    }
}

void sol() {
    int pos = 1;
    deque<tii> pq;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            pq.push_back({dist(x, y), x, y});
        }
    }

    sort(ALL(pq), comp);
    
    for (auto& elem : pq) {
        auto [d, x, y] = elem;
        hole[y][x] = pos++;
    }

    for (auto& row : hole) {
        for (int e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}