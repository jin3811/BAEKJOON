#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    int sum;
    string line;
    string temp;

    cin >> t;
    cin.ignore();
    
    while (t--) {
        sum = 0;
        temp = "";
        getline(cin, line);

        for (int i = 0; i < line.length(); i++) {
            temp += line[i];
            if (line[i] == ' ' || i == line.length() - 1) {
                sum += stoi(temp);
                temp = "";
            }
        }
        cout << sum << '\n';
    }
}