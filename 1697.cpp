#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

void solution(int start, int target, int time) {
    int ans;
    bool visited[MAX] = {false, };
    queue<pair<int, int>> q; // pair -> (location, time)
    q.push(make_pair(start, 0));
    visited[start] = true;

    while(!q.empty()) {
        int loc = q.front().first;
        int t = q.front().second;
        q.pop();

        if (loc == target) {
            ans = t;
            break;
        }

        if (loc + 1 < MAX && !visited[loc + 1]) {
            q.push(make_pair(loc + 1, t + 1));
            visited[loc + 1] = true;
        }
        if (loc * 2 < MAX && !visited[loc * 2]) {
            q.push(make_pair(loc * 2, t + 1));
            visited[loc * 2] = true;
        }
        if (loc - 1 >= 0 && !visited[loc - 1]) {
            q.push(make_pair(loc - 1, t + 1));
            visited[loc - 1] = true;
        }
    }
    cout << ans;
}

// bool visited_dfs[MAX] = {false, };
// int dfs_ans = 1000000000;
// void solution_dfs(int start, int target, int time) {
//     if(visited_dfs[start]) 
//         return;
    
//     if (start < 0 || start > MAX)
//         return;

//     if (start == target)
//         dfs_ans = min(dfs_ans, time);

//     visited_dfs[start] = true;
//     solution_dfs(start * 2, target, time + 1);
//     solution_dfs(start + 1, target, time + 1);
//     solution_dfs(start - 1, target, time + 1);
// }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int start, target;
    cin >> start >> target;
    solution(start, target, 0);
    // solution_dfs(start, target, 0);
    // cout << dfs_ans;
}