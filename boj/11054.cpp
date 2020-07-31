#include <iostream>
#include <vector>
#include <algorithm>
#define sci(N) scanf("%d", &(N))
using namespace std;

int N;
int A[1010], B[1010];
int dpA[1010], dpB[1010];
struct seg_tree {
  int sz = 1 << 18, bs = 1 << 17;
  int node[1 << 18];

  void update(int x, int v) {
    x |= bs;
    node[x] = v;
    while (x > 1) {
      x >>= 1;
      node[x] = max(node[x*2], node[x*2 + 1]);
    }
  }

  int query(int s, int e) {
    s |= bs;
    e |= bs;
    int retval = 0;
    while (s < e) {
      if (s % 2 == 1) retval = max (retval, node[s ++]);
      if (e % 2 == 0) retval = max (retval, node[e --]);
      s >>= 1;
      e >>= 1;
    }
    if (s == e) retval = max (retval, node[s]);
    return retval;
  }
}seg1, seg2;
int main () {
  sci(N);
  for (int i = 0; i < N; i ++) {
    sci(A[i]);
    B[i] = A[i];
  }
  for (int i = 0; i < N; i ++) {
    int tmp = seg1.query(0, A[i] - 1) + 1;
    seg1.update(A[i], tmp);
    dpA[i] = tmp;
  }
  reverse(B, B+N);

  for (int i = 0; i < N; i ++) {
    int tmp = seg2.query(0, B[i] - 1) + 1;
    seg2.update(B[i], seg2.query(0, B[i]-1) + 1);
    dpB[i] = tmp;
  }
  int result = 0;

  for (int i = 0; i < N; i ++) {
    result = max (result, dpA[i] + dpB[N-i-1] - 1);
  }
  printf("%d", result);

  return 0;
}
