#include <iostream>
#include <vector>
#include <algorithm>
#define sci(N) scanf("%d", &(N))
#define MOD 15746
using namespace std;
int N, K;

int w[110], v[110];
int dp[1000010];

int main () {
  sci(N), sci(K);
  for (int i=0;i<N;i++) {
    sci(w[i]), sci(v[i]);
  }

  dp[0] = 0;
  for (int i=0;i<N;i++) {
    for (int j=K;j>=0;j--) {
      if (w[i] + j > K) continue;
      dp[w[i]+j] = max(dp[w[i]+j], dp[j]+v[i]);
    }
  }
  int result = 0;
  for (int i=0;i<=K;i++) 
    result= max(result, dp[i]);
  printf("%d", result);

  return 0;
}
