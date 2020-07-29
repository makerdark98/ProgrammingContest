#include <iostream>
#include <string.h>
using namespace std;
#define sci(N) scanf("%d", &(N))
#define INF (1e9+7)

int data[20][20][20][20];
int in[20];
int p, m, t, d;
int N;

int dfs1(int p, int m, int t, int d, int now) {
  if (!p && !m && !t && !d) return now;
  if (p < 0 || m < 0 || t < 0 || d < 0) return -INF;
  int retval = -INF;
  retval = max(retval, dfs1(p-1, m, t, d, now + in[N - (p+m+t+d)]));
  retval = max(retval, dfs1(p, m-1, t, d, now - in[N - (p+m+t+d)]));
  retval = max(retval, dfs1(p, m, t-1, d, now * in[N - (p+m+t+d)]));
  retval = max(retval, dfs1(p, m, t, d-1, now / in[N - (p+m+t+d)]));
  return retval;
}
int dfs2(int p, int m, int t, int d, int now) {
  if (!p && !m && !t && !d) return now;
  if (p < 0 || m < 0 || t < 0 || d < 0) return INF;
  int retval = INF;
  retval = min(retval, dfs2(p-1, m, t, d, now + in[N - (p+m+t+d)]));
  retval = min(retval, dfs2(p, m-1, t, d, now - in[N - (p+m+t+d)]));
  retval = min(retval, dfs2(p, m, t-1, d, now * in[N - (p+m+t+d)]));
  retval = min(retval, dfs2(p, m, t, d-1, now / in[N - (p+m+t+d)]));
  return retval;
}
int main () {
  sci(N);
  for (int i = 0 ; i < N; i ++) sci(in[i]);
  sci(p), sci(m), sci(t), sci(d);
  printf("%d\n", dfs1(p,m,t,d,in[0]));
  printf("%d\n", dfs2(p,m,t,d,in[0]));
  return 0;
}
