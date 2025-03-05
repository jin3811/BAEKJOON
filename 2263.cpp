#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> post, in;
vector<pair<int,int>> tree;

void input() {
	cin >> n;
	post.resize(n), in.resize(n), tree.resize(n + 1);
	for(int& x : in) cin >> x;
	for(int& x : post) cin >> x;
}

void preorder(int r) {
	if (!r) return;

	auto& [cl, cr] = tree[r];

	cout << r << ' ';
	preorder(cl);
	preorder(cr);
}

int build_tree_post_in(int l, int r) {
	if (l >= r) return 0;

	int root = *post.rbegin(); post.pop_back();
	int idx = distance(in.begin(), find(in.begin() + l, in.begin() + r + 1, root));
	if (idx == n) return 0;
	
	auto& [cl, cr] = tree[root];
	cr = build_tree_post_in(idx + 1, r);
	cl = build_tree_post_in(l, idx);
	return root;
}

void sol() {
	int root = post[n - 1];
	build_tree_post_in(0, n);
	preorder(root);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}