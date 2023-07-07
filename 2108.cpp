#include <iostream>
#include <array>
#include <algorithm>
#include <functional>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int Min = 8001, Max = -8001;
    int maxElem;
    double avg = 0;
    array<int, 8001> numCount = {0}; // -4000 ~ 4000 -> 0 ~ 8000
    array<int, 8001>::iterator maxIndex;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // 입력받는다.
        avg += arr[i]; // 평균을 위한 총합
        Max = max(Max, arr[i]); // 최댓값 찾기
        Min = min(Min, arr[i]); // 최솟값 찾기
        numCount[arr[i] + 4000]++;
    }

    avg /= n; // 평균
    avg > 0 ? avg += 0.5 : avg -= 0.5; // 반올림

    sort(arr, arr + n, greater<>()); // 중앙값 찾기

    /*코드 역겨움 주의*/
    maxIndex = max_element(numCount.begin(), numCount.end()); // 최빈값 찾기. 첫번째 최빈값의 위치를 받는다.
    
     // 첫번째 최빈값 그 다음위치에서 최빈값을 다시 찾는다.
    if (*maxIndex != *max_element(maxIndex+1, numCount.end())) // 만약 등장횟수가 다르다면, 
        maxElem = (int)(maxIndex - numCount.begin()) - 4000; // 최빈값은 한개. 배열의 첫 주소로부터의 거리를 잰 후에 4000을 뺀다
    else // 등장횟수가 같다면
        maxElem = (int)(max_element(maxIndex + 1, numCount.end()) - numCount.begin()) - 4000; // 그 다음 최빈값의 위치로 동일한 과정.
    
    cout << (int)avg << '\n'; // 정수값으로 출력
    cout << arr[n / 2] << '\n'; // 중앙값
    cout << maxElem << '\n'; // 
    cout << Max - Min << '\n'; // 최대 - 최소 = 범위

    delete[] arr;
}