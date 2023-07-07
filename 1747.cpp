#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 2000001

bool is_palidrome(const int n){
    string rev;
    int num = n;
    while(num) {
        rev += (num % 10) + '0';
        num /= 10;
    }
    return n == stoi(rev);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<bool> seive(MAX_SIZE, true);
    // bool seive[MAX_SIZE];
    // fill(seive, seive + MAX_SIZE, true);
    seive[0] = seive[1] = false;
    
    // initializing
    for(int i = 2; i < MAX_SIZE; i++) {
        if (seive[i]) { 
            for (int p = 2; i*p < MAX_SIZE; p++) {
                seive[i*p] = false;
            }
        }
    }

    cin >> n;
    
    for(int i = n; ; i++) {
        if(seive[i] && is_palidrome(i)) {
            cout << i;
            break;
        }
    }
}