#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;

#define MOD 1000
class Matrix {
public:
  vvi data;
  int n, m;
  Matrix(int n, int m) 
    : data(n, vi(m, 0)), n(n), m(m) { }
  Matrix operator*(const Matrix& b) {
    Matrix tmp(n, b.m);

    for (int i = 0;i < n; i ++) {
      for (int j = 0; j < b.m; j ++) {
        for (int k = 0; k < m; k ++) {
          tmp.data[i][j] += (data[i][k] * b.data[k][j]);
        }
      }
    }
    for (int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        tmp.data[i][j] %= MOD;
      }
    }
    return tmp;
  }
};
Matrix fastpow(const Matrix& a, lld n) {
  if (n == 0) {
    Matrix identity(a.n, a.n);
    for(int i=0;i<a.n;i++) {
      identity.data[i][i] = 1;
    }
    return identity;
  }
  else if (n == 1)
    return a;
  Matrix t = fastpow(a, n / 2);
  t = t * t;
  if (n % 2 == 1) t = t * a;
  return t;
}

int main () {
  int N;
  lld b;
  scanf("%d", &N);
  scanf("%lld", &b);
  Matrix a(N, N);
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      scanf("%lld", &a.data[i][j]);
    }
  }
  Matrix result = fastpow(a, b);
  for (int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      printf("%lld ", result.data[i][j] % MOD);
    }
    printf("\n");
  }
  return 0;
}
