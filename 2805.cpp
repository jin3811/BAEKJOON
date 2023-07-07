#include <iostream>
#include <cstdint>
using namespace std;

int n;
uint64_t* arr;

uint64_t tree_len(uint64_t len) {
    uint64_t result = 0;

    for(int i = 0; i < n; i++)
        if (arr[i] > len) result += arr[i] - len;
    
    return result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    uint64_t mid, result = 0;
    uint64_t start = 1, end = 0;
    cin >> n >> m;

    arr = new uint64_t[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        end = end < arr[i] ? arr[i] : end;
    }

    while(start <= end) {
        mid = (start + end) / 2;
        if (tree_len(mid) < m) {
            end = mid - 1;
        }
        else {
            result = mid;
            start = mid + 1;
        }
    }
    cout << end;
    delete[] arr;
}
