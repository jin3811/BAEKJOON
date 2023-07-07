#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

array<int, 9> tall;

// 특정 원소가 들어있는지, 들어있다면 어디에 있는지 return한다. 만약 들어있지 않으면 -1을 return한다.
int elem_in_arr(int target, int except_index) { // except_index = 이 위치의 원소값은 검사하지 않는다. (그 위치는 이미 sum_tall에서 뺀 값이기 때문)
    int result = -1;
    for(int i = 0; i < 9; i++) {
        if (i != except_index && tall[i] == target)
            result = i;
    }
    return result;
}

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sum_tall = 0;
    int temp_sum; // 한명을 뺐을 때, 키의 총합
    int exceed; // temp_sum - 100, 100을 초과한 만큼의 값. 이 값을 함수를 통해 찾는다.
    int is_in; // elem_in_arr함수값을 받기 위한 변수

    for(int& x : tall) { // 입력
        cin >> x;
        sum_tall += x;
    }

    sort(tall.begin(), tall.end()); // 오름차순 출력을 위한 정렬
    
    for(int i = 0; i < 9; i++) {
        temp_sum = sum_tall - tall[i]; // i번째 키를 빼고
        exceed = temp_sum - 100; // 100을 초과한 만큼의 값을 저장
        is_in = elem_in_arr(exceed, i); // 함수 실행
        
        if (is_in != -1){ // 찾았다면 두명의 난쟁이를 지운다.
            tall[i] = -1;
            tall[is_in] = -1;
            break;
        }
    }
    for(int& x : tall) if (x != -1) cout << x << endl; // 출력
}