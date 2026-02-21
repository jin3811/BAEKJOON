#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[3], d1, d2;
	for(int i=0;i<3;i++) cin >> arr[i];
	sort(arr,arr+3);

	d1 = arr[1]-arr[0], d2 = arr[2]-arr[1];
	if (d1 == d2) cout << arr[0] - d1;
	else cout << arr[1] + (d1 == d2 / 2 ? d1 : -d2);
}