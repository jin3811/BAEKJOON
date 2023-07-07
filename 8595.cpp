#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char input;
    string temp = "";
    long long sum = 0;
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        cin >> input;
        if (isdigit(input)) {
            temp += input;
        }
        else if (isalpha(input)) {
            if (!temp.empty()) {
                sum += stoll(temp);
                temp = "";
            }
            else continue;
        }
    }
    if(!temp.empty()) sum += stoll(temp);
    cout << sum;
}