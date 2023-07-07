#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sugar;
    int result = 0;
    cin >> sugar;

    while(sugar > 0){
        if(sugar % 5 == 0){
            result += sugar / 5;
            sugar %= 5;
            break;
        }
        else {
            sugar -= 3;
            result++;
        }
    }
    if(sugar) cout << -1;
    else cout << result;
}