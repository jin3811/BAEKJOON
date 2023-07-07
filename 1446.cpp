#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using pii = pair<int, int>;

int N, D;
vector<vector<pii>> graph;

void input() {
    int start, end, len;
    cin >> N >> D;

    graph.resize(D + 1);
    
    for(int i = 0; i < N; i++) {
        cin >> start >> end >> len;
        
        if (len >= end - start) continue;
        if (end > D) continue;

        graph[start].push_back({len, end});
    }
}

void sol() {
    int dist_arr[D + 1];
    fill(dist_arr, dist_arr + D + 1, INF);
   
    dist_arr[0] = 0;
    for(int i = 0; i <= D; i++) {
        if(i) dist_arr[i] = min(dist_arr[i], dist_arr[i - 1] + 1);

        for(auto& elem : graph[i]) {
            dist_arr[elem.second] = min(dist_arr[elem.second], dist_arr[i] + elem.first);
        }
    }

    cout << dist_arr[D];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    sol();    
}