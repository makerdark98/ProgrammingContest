//
// Created by lmu on 18. 9. 26.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%lld ", (n))
#define MOD 1000000007LL
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main(){
  int L, n, m;
  vi D(6010, 0), f(6010), inv(6010), finv(6010);
  vi a, b, LS;
  int nowLength = 0;
  int ai = 0, bi =0, as = 0, bs = 0;
  int i, j;

  f[0] = f[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for (i=2;i<6010;i++) {
    f[i] = (f[i-1]*i) % MOD;
    inv[i] = (MOD - (MOD / i)* inv[MOD%i] % MOD) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }

  sci(L), sci(n); a.resize(n);
  for (i=0;i<n;i++) scl(a[i]);
  sci(m); b.resize(m);
  for (i=0;i<m;i++) scl(b[i]);

  while (as < L || bs < L) {
    if (as == bs) {
      as += a[ai++];
      bs += b[bi++];
      nowLength += 2;
    }
    else if (as < bs) {
      as += a[ai++];
      nowLength ++;
    } 
    else {
      bs += b[bi++];
      nowLength ++;
    }

    if (as == bs) {
      if (nowLength > 2)
        LS.push_back(nowLength -2);
      nowLength = 0;
    }
  }

  /* Calculate D */
  D[0] = D[1] = 1;
  for (i = 2; i <= 2 * L; i++) {
    for (j = i-2; j >= 0; j-= 2) {
      lld t = D[j] * D[i-1-j] % MOD;
      t = (t * f[i-1]) % MOD;
      t = (t * finv[j]) % MOD;
      t = (t * finv[i - 1 - j]) % MOD;
      D[i] = (D[i] + t) % MOD;
    }
  }

  lld result = 1, s = 0;
  for (auto& l : LS) {
    result = (result * finv[l]) % MOD;
    result = (result * D[l]) % MOD;
    s += l;
  }

  result = (result * f[s]) % MOD;
  printf("%lld %lld\n", s, result);

  return 0;
}
