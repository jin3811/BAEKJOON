#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int score, sum, max_id = 0, max_score = 0;
    for(int i = 1; i <= 5; i++) {
        sum = 0;
        for(int i = 0; i < 4; i++) {
            cin >> score;
            sum += score;
        }
        if (sum > max_score){
            max_score = sum;
            max_id = i;
        }
    }
    cout << max_id << ' ' << max_score;
}