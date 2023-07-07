#include <iostream>
using namespace std;
typedef unsigned int uint;

int count_lan_cable(int* arr, int arr_len, unsigned int len) {
    int count = 0;
    
    for(int i = 0; i < arr_len; i++) 
        count += arr[i]/len;
    
    return count;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n;
    uint start = 1, end = 0;
    uint result;
    uint mid;

    cin >> k >> n;

    int* arr = new int[k];
    
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        end = arr[i] > end ? arr[i] : end;
    }

    while (start <= end) {
        mid = (start + end) / 2;
        if (count_lan_cable(arr, k, mid) >= n) {
            start = mid + 1;
            result = mid;
        } else 
            end = mid - 1;
    }
    cout << result;
    delete[] arr;
}