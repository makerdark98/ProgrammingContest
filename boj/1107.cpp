#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define sci(n) scanf("%d", &(n))
#define SIZE 1001000

int N, M, t, dp[SIZE];
bool chk[10];
queue<int> q;

void init(int base);
int main () {
  sci(N), sci(M);
  for (int i=0;i<M;i++) { sci (t); chk[t] = true; }
  fill(dp, dp+SIZE, -1);
  dp[100] = 0;
  for (int i=0;i<SIZE;i++) dp[i]=abs(100-N);
  for (int i=0;i<10;i++) {
    if (!chk[i]) { dp[i] = 1; init(i); }
  }

  for (int i=0;i<SIZE;i++) { if(dp[i] != abs(100 - N)) q.push(i); }

  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    if (f+1 < SIZE && dp[f] + 1 < dp[f+1]) {
      dp[f+1] = dp[f] + 1;
      q.push(f+1);
    }

    if (f-1 >= 0 && dp[f] + 1 < dp[f-1]) {
      dp[f-1] = dp[f] + 1;
      q.push(f-1);
    }
  }
  printf("%d", dp[N]);
  return 0;
}

void init(int base) {
  if (base == 0) return;
  for (int i=0;i<10;i++) {
    if (!chk[i] && base * 10 + i < SIZE && dp[base] + 1 < dp[base*10+i]) {
      dp[base * 10 + i] = dp[base] + 1;
      init(base * 10 + i);
    }
  }
}
