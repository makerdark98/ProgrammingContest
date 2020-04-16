#include <iostream>
using namespace std;
using lld = long long;

int main () {
  for(int i=1;i<100;i++) {
    for(int j=1;j<100;j++) {
      for (int k=1;k<100;k++){
        for(int l=1;l<100;l++){
      lld u, v, a, b, c;
      u = i^j^k^l;
      v = i+j+k+l;
      //scanf("%lld %lld", &u, &v);
      a = ((v-u) >> 1) | u;
      b = (v-u) >> 1;
      c = ((v-u) >> 1) & u;
      if (b == 0) {
        b = (a & -a);
        a = a & ~b;
      }
      bool success = u == (a^b^c) && v == a + b +c && a > 0 && b > 0 && c >=0;
      if (!success) {
        printf("xor : %lld sum : %lld, xor : %lld sum :%lld\n",u, v, a^b^c, a + b + c);
        printf("%d %d %lld %lld\n", i, j, a, b);
      }

      /*
      if (u % 2 != v % 2) {
        printf("-1");
        return 0;
      }
      if (a == 0 && b == 0) {
        printf("0");
      }

      if (a == 0) {
        printf("-1");
        return 0;
      }

      if (c == 0) {
        printf("2\n%lld %lld",a, b);
        return 0;
      }
      printf("3\n%lld %lld %lld",a, b, c);
      */

    }
  }
  }
  }
  return 0;
}
