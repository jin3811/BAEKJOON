#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, k, arr[500000], cnt;

void input() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void merge(int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 0;
	int tmp[r - p + 1];
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}
	}
	while(i <= q) {
		tmp[t++] = arr[i++];
	}
	while(j <= r) {
		tmp[t++] = arr[j++];
	}
	i = p; t = 0;
	while (i <= r) {
		arr[i++] = tmp[t++];
		if (++cnt == k) {
			cout << arr[i - 1];
			exit(0);
		}
	}
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

void sol() {
	merge_sort(0, n - 1);
	cout << -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}