#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string str;
    string name;
    string::iterator iter;

    cin >> t;
    while (t--) {
        cin.ignore();
        getline(cin, name);
        str = "god";
        iter = name.begin();
        while (*iter++ != ' ');
        for (; iter != name.end(); iter++)
            if (*iter != ' ') str += *iter;
        cout << str << '\n';
    }
}