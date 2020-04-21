#include <iostream>
using namespace std;
using lld = long long;
lld N, k;

lld getKth(lld Num) {
  lld result = 0;
  lld r = 1;
  lld c = 1;
  while (r <= N && r < Num) {
    r ++;
  }
  r--;

  while (c <= N) {
    if (r * c < Num) {
      c ++;
      result += r;
    } else {
      r --;
    }
  }
  return result;
}

lld search (lld k) {
  lld s = 1, e = N*N + 1;
  lld m;
  while (s < e) {
    m = (s+e)/2;
    lld p = getKth(m);
    if (p >= k) {
      e = m;
    } else {
      s = m + 1;
    }
  }
  return e - 1;
}

int main () {
  scanf("%lld", &N);
  scanf("%lld", &k);
  printf("%lld", search(k));
  return 0;
}
