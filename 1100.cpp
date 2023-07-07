#include <iostream>
#include <string>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        cin >> str;
        for (int j = i & 1 ? 1 : 0; j < 8; j += 2)
            if (str[j] == 'F') ++cnt;
    }
    cout << cnt;
}