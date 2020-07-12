#include <iostream>
#define sci(n) scanf("%d", &(n))
using namespace std;
#define MOD 1000000003LL
using lld = long long;
lld dp[1010][1010];

int main () {
  int i, j;
  int N, K;
  sci(N), sci(K);


  for (i = 0; i < N; i ++) {
    dp[i][1] = i;
    dp[i][0] = 1;
  }

  for (i = 2; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      dp[i][j] = dp[i-2][j-1] + dp[i-1][j];
      dp[i][j] %= MOD;
    }
  }

  printf("%lld", (dp[N-3][K-1] + dp[N-1][K]) % MOD);
  return 0;
}
