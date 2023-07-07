#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int input[5];
    for(int i = 0; i < 5; i++) cin >> input[i];
    sort(input, input + 5);
    cout << accumulate(input, input+5, 0) / 5<< '\n' << input[2];
}