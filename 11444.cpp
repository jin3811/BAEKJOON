/**
 * boj/11444
 * 
 * 피보나치 수열 N번째 수를 구하는 단순?한 문제이다.
 * 다만 n이 엄청나게 클뿐이다. 100경...
 * 
 * 따라서 O(logN)의 시간복잡도로 줄일 필요가 있다.
 * 
 * 피보나치 수열은 행렬로 나타낼 수 있다.
 * F = |1 1|
 *     |1 0|
 * 을 n제곱하면 F12또는 F21의 값이 우리가 원하는 Fn이 된다. 다음 두 글을 참조
 * https://namu.wiki/w/피보나치%20수열#s-8.1
 * https://ohgym.tistory.com/1
 * 빠른 행렬 제곱을 이용해 시간복잡도를 줄일 수 있다.
 */
#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1000000007
using namespace std;
using ll = long long;

class Matrix2D {
	vector<vector<ll>> mat;
	int row, col;
public:
	Matrix2D(int row = 0, int col = 0) {
		init(row, col);
	}

	Matrix2D(const vector<vector<ll>>& data) {
		this->row = (int)data.size();
		this->col = (int)data[0].size();
		mat = data;
	}

	void init(int row = 0, int col = 0) {
		this->row = row;
		this->col = col;
		this->mat.resize(row, vector<ll>(col, 0));
	}

	Matrix2D operator*(const Matrix2D& other) {
		ll r;
		Matrix2D tmp(this->row, other.col);

		for(int k = 0; k < this->col; k++) {
			for(int i = 0; i < this->row; i++) {
				r = mat[i][k];
				for(int j = 0; j < other.col; j++) {
					tmp.mat[i][j] += ((r % MOD) * (other.mat[k][j] % MOD)) % MOD;
					tmp.mat[i][j] %= MOD;
				}
			}
		}

		return tmp;
	}
	
	Matrix2D pow(ll a) {
		if (a == 1) return *this;

		Matrix2D tmp(pow(a / 2));

		if (a % 2 == 1) return (*this) * tmp * tmp;
		else return tmp * tmp;
	}

	ll getElem(int r, int c) { return mat[r][c]; }
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	vector<vector<ll>> fib = { {1, 1}, {1, 0} };
	ll n;

	cin >> n;
	cout << Matrix2D(fib).pow(n).getElem(1, 0);
}