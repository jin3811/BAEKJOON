#include <vector>
#include <algorithm>
int kth(std::vector<int> &a, int k) {
    sort(a.begin(), a.end());
	return a[k-1];
}
