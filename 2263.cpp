/**
 * boj/2263
 * 
 * 후위 순회의 맨 오른쪽 원소는 현재 알고자 하는 (서브)트리의 루트이다.
 * 후위 순회의 맨 오른쪽 원소를 pop하고, 해당 루트를 중위 순회한 결과에서 찾는다. 해당 위치의 좌우로 서브트리의 중위 순회결과임을 알 수 있다.
 * 재귀적으로 파고 들어가며 트리를 원복한다. 그 후, 전위순회하면 답.
 */

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
	int idx = distance(in.begin(), find(in.begin() + l, in.begin() + r, root));
	if (idx == r) return 0;
	
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