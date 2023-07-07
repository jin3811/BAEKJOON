#include <bits/stdc++.h>
using namespace std;
deque<int> dq;

int find_index(int target){
    for(int i = 0; i < dq.size(); i++) {
        if (dq[i] == target) return i; 
    }
    return -1;
}

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);   
    cin.tie(nullptr);

    /*
     * 생각
     * 앞 뒤에서 push & pop이 발생 -> deque
     * 연산1: std::deque.pop_front()
     * 연산2: std::deque.push_back(std::deque.front()); std::deque.pop_front()
     * 연산3: std::deque.push_front(std::deque.back()); std::deque.pop_back()
    */

    vector<int> cmd;
    int n, m, idx;
    int cnt = 0; // 2, 3번연산 횟수
    cin >> n >> m;

    dq.resize(n);
    cmd.resize(m);
    iota(dq.begin(), dq.end(), 1);

    for(int& x : cmd) cin >> x;

    for(const int& x : cmd) {
        idx = find_index(x);
        if (n / 2. > idx){
            while(dq.front() != x){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else {
            while(dq.front() != x){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front();
        n--;
    }
    cout << cnt;
}