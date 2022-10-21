#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

#define fin freopen("in.txt", "r", stdin)
#define fout freopen("out.txt", "w", stdout)

struct Matrix {
    vector<vector<ll>> A;
    int row, col;

    Matrix(int row = 0, int col = 0) : row(row), col(col) {
        A.resize(row);
        for (int i = 0; i < row; ++i) {
            A[i].resize(col);
            for (int j = 0; j < col; ++j)
                A[i][j] = 0;
        }
    }
};
Matrix operator*(const Matrix& A, const Matrix& B) {
    Matrix C(A.row, B.col);
    for (int i = 0; i < A.row; ++i) {
        for (int j = 0; j < B.col; ++j) {
            for (int k = 0; k < A.col; ++k) {
                C.A[i][j] += A.A[i][k] * B.A[k][j] % MOD;
            }
        }
    }
    return C;
}

ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.row; ++i) {
        for (int j = 0; j < matrix.col; ++j)
            os << matrix.A[i][j] << " ";
        cout << '\n';
    }
    return os;
}

Matrix Identity(int n) {
    Matrix mat(n, n);
    for (int i = 0; i < n; ++i)
        mat.A[i][i] = 1;
    return mat;
}

Matrix fastPow(const Matrix& base, int pow) {
    if (pow == 0) return Identity(base.col);
    if (pow == 1) return base;
    Matrix tmp = fastPow(base, pow / 2);
    tmp = tmp * tmp;
    if (pow & 1)
        tmp = tmp * base;
    return tmp;
}

int main() {
//    fin;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL)
    Matrix mat(4, 4), base(4, 1), tmp;
    mat.A[0][1] = mat.A[1][2] = mat.A[3][3] = 1;
    base.A[0][3] = 1;
    
    int t;
    cin >> t;
    int tc = 1;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        mat.A[2][0] = b; mat.A[2][2] = a; mat.A[2][3] = c;
        tmp = fastPow(mat, n);
        tmp = tmp * base;
        cout << "Case " << tc++ << ": " << tmp.A[0][0] << '\n';
    }
    return 0;
}