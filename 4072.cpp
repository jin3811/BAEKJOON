#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    string token;
    queue<string> q;

    while (true) {
        getline(cin, line);
        if (line == "#") break;

        stringstream sstream(line);

        while(getline(sstream, token, ' ')) {
            reverse(token.begin(), token.end());
            q.push(token);
        }

        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
        
        cout << '\n';
    }
}