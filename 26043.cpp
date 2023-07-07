#include <bits/stdc++.h>
#define endl '\n'
#define ALL(X) X.begin(), X.end()
using namespace std;

void print(vector<int>& v) {
    if (v.size() == 0) cout << "None";
    else {
        for (int& x : v) {
            cout << x << " ";
        }
    }
    cout << endl;
}

void sol(int tc) {
    int command, a, b;
    queue<pair<int, int>> q;
    vector<int> prefer, notPrefer, notEat;

    while (tc--) {
        cin >> command;
        
        if (command == 1) {
            cin >> a >> b;
            q.push({a, b});
        }
        else if (command == 2) {
            cin >> b;
            auto student = q.front();
            q.pop();
            student.second == b ? prefer.push_back(student.first) : notPrefer.push_back(student.first);
        }
    }
    
    while (!q.empty()) {
        notEat.push_back(q.front().first);
        q.pop();
    }

    sort(ALL(prefer));
    sort(ALL(notPrefer));
    sort(ALL(notEat));

    print(prefer);
    print(notPrefer);
    print(notEat);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    sol(tc);
}