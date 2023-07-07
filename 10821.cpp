#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cnt = 0;
    string str;

    cin >> str;
    stringstream sstream(str);
    while (getline(sstream, str, ',')) ++cnt;

    cout << cnt;
}