#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define INF 1e9

int dist[100][100];
int n;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == 0) dist[i][j] = INF;
        }
    }
}

void sol() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) 
            cout << (dist[i][j] == INF ? 0 : 1) << ' ';
        cout << endl;
    }            
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    sol();
}