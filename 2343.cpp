#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int blue_ray_count(int amount){
    int sum = 0;
    int cnt = 1; // 기본적으로 하나에는 담기기 때문에 cnt를 1로 초기화
    for(int i = 0; i < v.size() - 1; i++){
        sum += v[i];
        if(sum + v[i + 1] > amount){ // 꽉 채워졌다면
            sum = 0; // 초기화
            ++cnt; // 개수 증가
        }
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    int start = -1;
    int end = 0;
    int mid, result, temp;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        end += temp; // end의 초기값은 모든 값의 합
        start = max(temp, start); //start의 초기값은 모든 값중에서 제일 큰 값.
    }

    while(start <= end){ // 이분탐색
       mid = (start + end) >> 1;
       
       if(blue_ray_count(mid) <= m) { // 개수가 적다면 
           end = mid - 1;
           result = mid;
       }
       else {
           start = mid + 1;
       }
    }
    cout << result;
}