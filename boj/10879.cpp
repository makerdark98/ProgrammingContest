#include <iostream>
#include <cmath>
#define sci(n) scanf("%d", &(n))
using namespace std;
#define SIZE 1000001
#define MAX 99999999

int dp[SIZE];
int getDP(int n) {
  n = abs(n);

  if (n >= SIZE) return MAX;

  if (dp[n]) return dp[n];

  dp[n] = MAX;
  int base = 1;
  int tmp = 1;
  while (base < n){
    base <<= 1;
    tmp ++;
  }
  if (base == n) dp[n] = tmp;
  while (base > 0) {
    dp[n] = min (dp[n], getDP(base) + getDP(n - base) + 4);
    base >>= 1;
  }
  return dp[n];
}

int main () {
  int T;
  sci(T);
  dp[1] = 1;
  for(int i=0;i<T;i++) {
    int a;
    sci(a);
    printf("%d\n", getDP(a));
  }
  return 0;
}
