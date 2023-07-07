#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
using namespace std;

int n, m;
int graph[101][101];

void input() {
    int st, ed, len;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = i == j ? 0 : INF;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> st >> ed >> len;
        graph[st][ed] = min(graph[st][ed], len);
    }
}

void sol() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
        cout << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    sol();
}