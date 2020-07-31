#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define sci(N) scanf("%d", &(N))
#define INF (1e9 + 7)

struct seg_tree {
  int sz = 1 << 18, bs = 1 << 17;
  int data[1 << 18];

  void update(int x, int v) {
    x |= bs;
    data[x] = v;
    while (x > 1) {
      x >>= 1;
      data[x] = max(data[x * 2], data[x * 2 + 1]);
    }
  }

  int query(int s, int e) {
    s |= bs;
    e |= bs;
    int retval = 0;
    while (s < e) {
      if (s & 1) retval = max(retval, data[s++]);
      if (e & ~1) retval = max(retval, data[e--]);
      s >>= 1;
      e >>= 1;
    }
    if (s == e) retval = max(retval, data[s]);
    return retval;
  }
}seg;
pair<int,int> A[1010];
int main () {
  int N;
  sci(N);
  for (int i = 0; i < N; i ++) {
    sci(A[i].first);
    A[i].second = i;
  }
  int m=0;
  for (int i = 0; i < N; i ++) {
    seg.update(A[i].first, seg.query(0, A[i].first-1) + 1);
    m=max(m,A[i].first);
  }

  printf("%d", seg.query(0, m));
  return 0;
}
