#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int k, m;
// 북 동 남 서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dig(unsigned long long x) {
    if (x < 10) return x;
    else {
        int param = 0;
        while(x) {
            param += x % 10;
            x /= 10;
        }
        return dig(param);
    }
}

int get_cycle() {
    for (int cycle = 2; cycle <= 2 * k; cycle += 2) {
        int i = 0;
        int num = 1;
        vector<int> first, second;
        
        for (; i < cycle / 2; i++) {
            first.push_back(dig(num));
            num *= m;
        }
        for(; i < cycle; i++) {
            second.push_back(dig(num));
            num *= m;
        }
        if (first == second) return cycle / 2;
    }
}

void sol() {
    int gold_num = 1;
    int go_pos;

    int cycle = get_cycle();
    pair<int, int> treasure = {0, 0};
    
    
    // for(int i = 1; i <= k; i++) {
    //     go_pos = dig(gold_num);
    //     gold_num *= m;
        
    //     if (i % 4 == 1) {
    //         treasure.second += go_pos;
    //     }
    //     else if (i % 4 == 2) {
    //         treasure.first += go_pos;
    //     }
    //     else if (i % 4 == 3) {
    //         treasure.second -= go_pos;
    //     }
    //     else {
    //         treasure.first -= go_pos;
    //     }
    // }
    
    for (int i = 1; i <= k / cycle; i++) {
        go_pos = dig(gold_num);
        gold_num *= m;
        
        if (i % 4 == 1) {
            treasure.second += go_pos;
        }
        else if (i % 4 == 2) {
            treasure.first += go_pos;
        }
        else if (i % 4 == 3) {
            treasure.second -= go_pos;
        }
        else {
            treasure.first -= go_pos;
        }
    }
    
    
    
    
    cout << treasure.first << " " << treasure.second << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tcase;
    cin >> tcase;
    while(tcase--) {
        cin >> k >> m;
        sol();
    }
}
