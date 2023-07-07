#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    int lower, upper, num, blank;    

    while (getline(cin, str)) {
        lower = 0;    
        upper = 0;    
        num = 0;    
        blank = 0;    

        for (const auto& x : str) {
            if (islower(x)) ++lower;
            else if (isupper(x)) ++upper;
            else if (isdigit(x)) ++num;
            else if (isblank(x)) ++blank;
        }
        cout << lower << ' ' << upper << ' ' << num << ' ' << blank << '\n';
    }
}