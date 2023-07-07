#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int temp;
    array<bool, 31> submit;
    fill(submit.begin(), submit.end(), false);
    for(int i = 0; i < 28; i++) {
        cin >> temp;
        submit[temp] = true;
    }
    for(int i = 1; i < 31; i++)
        if(!submit[i]) cout << i << '\n';
}