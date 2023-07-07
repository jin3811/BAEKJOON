#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int target;
priority_queue<int> pq;
queue<pair<int, int>> q;

void input() {
    while(!pq.empty()) pq.pop();
    while(!q.empty()) q.pop();
    int cnt, importance;
    cin >> cnt >> target;
    for (int i = 0; i < cnt; i++) {
        cin >> importance;
        q.push({importance, i});
        pq.push(importance);
    }
}

void sol() {
    int ans = 1;
    while(!q.empty()) {
        if(q.front().first < pq.top()) {
            q.push(q.front());
            q.pop();
        }
        else {
            if (q.front().second == target) {
                cout << ans << endl;
                break;
            }
            else {
                q.pop();
                pq.pop();
                ans++;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        input();
        sol();
    }
}