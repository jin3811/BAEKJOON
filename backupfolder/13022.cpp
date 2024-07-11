#include <bits/stdc++.h>
using namespace std;

string wolf;
char spell[5] = "wolf";

int get_idx(char c) {
    for (int i = 0; i < 4; i++) {
        if (c == spell[i]) return i;
    }
}

bool is_sorted(char prev, char curr) {
    int cur_idx = get_idx(curr);
    int pre_idx = get_idx(prev);
    if (cur_idx != (pre_idx + 1) % 4) {
        return false;
    }
    return true;
}

void sol() {
    bool result = true;
    char prev = wolf[0], curr;
    int prev_cnt = -1, curr_cnt = 0;

    if (prev != 'w' || wolf.length() < 4) {
        cout << 0;
        return;
    }
    
    for (int i = 0; i < wolf.length(); i++) {
        curr = wolf[i];
        curr_cnt++;

        // 문자열이 바뀐 경우,
        if (curr != prev) {
            // 등장 순서가 맞는지 체크한다.
            if(!is_sorted(prev, curr)) {
                cout << 0;
                return;
            }

            // 개수는 제대로 나왔는지 체크한다.
            if (prev_cnt != -1 && prev_cnt != curr_cnt) {
                cout << 0;
                return;
            }

            if (curr == 'f') {
                prev = 'w';
                prev_cnt = -1;
            }
            else {
                prev = curr;
                prev_cnt = curr_cnt;
            }
            curr_cnt = 0;
        }
        // else {
        //     curr_cnt++;
        // }
    }
    // if (prev_cnt != curr_cnt) cout << 0;
    // else 
    cout << 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> wolf;
    sol();
}	