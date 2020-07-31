#include <iostream>
#include <vector>
#include <algorithm>
#define sci(N) scanf("%d", &(N))
using namespace std;

int N;
int A[1010], B[1010];
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
}seg;
int main () {
  sci(N);
  for (int i = 0; i < N; i ++) {
    int a, b;
    sci(a), sci(b);
    A[a] = b;
    B[a] = b;
  }
  reverse(B, B+1010);
  for (int i = 0; i < 1010; i ++) {
    if (A[i]) seg.update(A[i], seg.query(0, A[i] - 1) + 1);
  }
  printf("%d", N - seg.query(0, 1010));
  return 0;
}
