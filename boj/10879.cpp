#include <iostream>
#include <cmath>
#define sci(n) scanf("%d", &(n))
using namespace std;

int dp[1000001];
int getDP(int n) {
  if (n > 1000001) return 99999999;
  if (n < 0) return 99999999;
  if (dp[n] != 0) return dp[n];
  int base = 1;
  int tmp = 1;
  while (base <n){
    base <<= 1;
    tmp ++;
  }
  if (base == n) {
    dp[n] = tmp;
    return dp[n];
  }
  dp[n] = getDP(base) + getDP(base-n) + 4;
  base >>= 1;
  tmp = getDP(base) + getDP(n-base) + 4;
  dp[n] = min (dp[n], tmp);
  return dp[n];
}

int main () {
  int T;
  sci(T);
  dp[0] = 1; dp[1] = 1;
  for(int i=0;i<T;i++) {
    int a;
    sci(a);
    printf("%d\n", getDP(abs(a)));
  }
  return 0;
}
