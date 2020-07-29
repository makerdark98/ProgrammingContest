#include <iostream>
#include <cmath>
using namespace std;
#define sci(N) scanf("%d", &(N))
#define INF 1e9

using lld = long long;

int N;
int in[21][21];
int chk[21];

int check() {
  lld a_result = 0;

  int cnt = 0;
  for (int i =0 ; i < N; i++) {
    cnt += chk[i];
  }
  if (cnt != N/2) return INF;
  for (int i = 0 ; i < N; i ++) {
    if (chk[i]) continue;
    for (int j = 0; j < N; j ++) {
      if (!chk[j]) a_result += in[i][j];
    }
  }

  lld b_result = 0;
  for (int i = 0; i < N; i ++) {
    if (!chk[i]) continue;
    for (int j = 0; j < N; j ++) {
      if (chk[j]) b_result += in[i][j];
    }
  }

  return abs(a_result - b_result);
}

int dfs(int idx) {
  if (idx == N) return check();
  int retval = INF;

  chk[idx] = 0;
  retval = dfs(idx + 1);
  chk[idx] = 1;
  retval = min (dfs(idx + 1), retval);

  return retval;
}

int main () {
  sci(N);
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < N; j ++) {
      sci (in[i][j]);
    }
  }

  printf("%d", dfs(0));
  return 0;
}
