#include <bits/stdc++.h>
using namespace std;

// 이분 탐색
int bridge_len;
int lamp_cnt;
int st, ed;
int* lamp_position;

void input(){
    cin >> bridge_len >> lamp_cnt;
    lamp_position = new int[lamp_cnt];
    st = 1;
    ed = bridge_len;
    for(int i = 0; i < lamp_cnt; i++) {
        cin >> lamp_position[i];
        ed = max(lamp_position[i] , ed);
    }
}

bool shine_all(int height) {
    for (int i = 0; i < lamp_cnt; i++) {
        if (i == 0) {
            if (lamp_position[i] - height > 0) return false;
        }

        if (lamp_position[i] - height > lamp_position[i - 1] + height) return false;
        
        if (i == lamp_cnt - 1) {
            if (lamp_position[i] + height < bridge_len) return false;
        }
    }
    return true;
}

void solution() {
    int mid;
    int result = 0;

    while (st <= ed) {
        mid = (st + ed) / 2;
        
        if (shine_all(mid)) {
            ed = mid - 1;
            result = mid;
        }
        else {
            st = mid + 1;
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solution();
    delete[] lamp_position;
}

/* 
// 선형탐색
int bridge_len;
int lamp_cnt;
int* lamp_position;

void input(){
    cin >> bridge_len >> lamp_cnt;
    lamp_position = new int[lamp_cnt];
    for(int i = 0; i < lamp_cnt; i++) {
        cin >> lamp_position[i];
    }
}

void solution() {
    int result = 1;
    for(int i = 0; i < lamp_cnt; i++) {
        if (i == 0) {
            result = max(result, lamp_position[i]);
        }
        else {
            result = max(result, (lamp_position[i] - lamp_position[i - 1] + 1) / 2);
        }
        if (i == lamp_cnt - 1) {
            result = max(result, bridge_len - lamp_position[i]);
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solution();
    delete[] lamp_position;
}
*/