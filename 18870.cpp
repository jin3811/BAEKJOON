#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, temp; 
    cin >> n;
    vector<int> v; // 원본 좌표
    vector<int> cv; // 정렬하기 위한 좌표
    vector<int>::iterator iter; // 반복자

    for(int i = 0; i < n; i++) { // 입력
        cin >> temp;
        v.push_back(temp);
        cv.push_back(temp);
    }
    
    sort(cv.begin(), cv.end()); // 정렬
    cv.erase(unique(cv.begin(), cv.end()), cv.end()); // 중복제거
    
    for(iter = v.begin(); iter != v.end(); iter++) { // 원본 좌표값을 압축하여 출력
        // 원본좌표값을 정렬한 벡터에서 위치를 찾고, 정렬한 벡터의 시작주소간의 거리를 출력. 
        cout << lower_bound(cv.begin(), cv.end(), *iter) - cv.begin() << ' '; 
    }
}