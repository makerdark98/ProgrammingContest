#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
using vi = vector<lld>;
#define scl(n) scanf("%lld", &(n))
int main () {
  lld N, K, M;
  scl(N),scl(K),scl(M);

  vi f(N+1), inv(N+1), finv(N+1);

  f[0] = f[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;

  for (lld i = 2;i <= N;i++) {
    f[i] = f[i-1] * i % M;
    inv[i] = (M - M / i) * inv[M % i] % M;
    finv[i] = finv[i-1] * inv[i] % M;
  }


  for (lld i=1;i<=N; i++) {
    printf("%lld %lld %lld %lld\n", i, f[i], inv[i], finv[i]);
  }
  lld t = f[N] % M;
  t = t * finv[K] % M;
  t = t * finv[N-K] % M;
  printf("%lld", t);

  return 0;
}
