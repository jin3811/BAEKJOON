#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using ll = long long;

class Matrix2D {
	vector<vector<ll>> mat;
	int row, col;
public:
	Matrix2D(const Matrix2D& origin) {
		this->mat = origin.mat;
		this->row = origin.row;
		this->col = origin.col;
	}

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

    Matrix2D input() {
		for(auto& y : mat) {
			for(auto& x : y) {
				cin >> x;
			}
		}
        return *this;
    }

	Matrix2D operator*(const Matrix2D& other) {
		int r;
		Matrix2D tmp(this->row, other.col);

		for(int k = 0; k < this->col; k++) {
			for(int i = 0; i < this->row; i++) {
				r = mat[i][k];
				for(int j = 0; j < other.col; j++) {
					tmp.mat[i][j] += r * other.mat[k][j];
					tmp.mat[i][j] %= 1000;
				}
			}
		}

		return tmp;
	}

	void print() {
		for(auto& y : mat) {
			for(auto& x : y) cout << x << ' ';
			cout << endl;
		}
	}
	
	Matrix2D pow(ll a) {
		if (a == 1) return *this;

		Matrix2D tmp(pow(a / 2));

		if (a % 2 == 1) return (*this) * tmp * tmp;
		else return tmp * tmp;
	}

	vector<vector<ll>> getData() { return mat; }

    ll getElem(int r, int c) { return mat[r][c]; }
};