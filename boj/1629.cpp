#include <iostream>
#define scl(N) scanf("%lld", &(N))
using namespace std;
using lld = long long;
lld fastpow(lld A, lld B, lld C) {
  if (B == 1) return A;
  if (B == 0) return 1;

  lld tmp = fastpow(A, B/2, C);
  tmp = tmp * tmp % C;
  tmp *= B % 2 ? A : 1;
  tmp %= C;
  return tmp;
}
int main () {
  lld A, B, C;
  scl(A), scl(B), scl(C);
  printf("%lld", fastpow(A % C, B, C));
  return 0;
}
