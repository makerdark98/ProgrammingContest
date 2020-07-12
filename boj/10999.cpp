#include <iostream>
#include <vector>
#include <cmath>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define MAX_N 1000000
#define MID(s, e) (((s) + (e))/2)
#define LCHILD(i) (((i) << 1))
#define RCHILD(i) (((i) << 1) + 1)
using namespace std;
using lld = long long;
struct node_t { lld value; lld lazy; };
node_t seg[4 * MAX_N];
lld N;
int build(vector<lld>& data, int idx, int s, int e) {
  if (s == e) return seg[idx].value = data[s];
  return seg[idx].value = build(data, LCHILD(idx), s, MID(s, e)) + build(data, RCHILD(idx), MID(s, e) + 1, e);
}
void update_lazy(int idx, int s, int e) {
  if (seg[idx].lazy != 0) {
    seg[idx].value += (e - s + 1) * seg[idx].lazy;
    if (s != e) {
      seg[LCHILD(idx)].lazy += seg[idx].lazy;
      seg[RCHILD(idx)].lazy += seg[idx].lazy;
    }
    seg[idx].lazy = 0;
  }
}
lld update_range(int idx, lld diff, int s, int e, int l, int r) {
  update_lazy(idx, s, e);
  if (r < s || l > e)
    return seg[idx].value;
  if (l <= s && e <= r) {
    seg[idx].lazy += diff;
    update_lazy(idx, s, e);
    return seg[idx].value;
  }

  return seg[idx].value = update_range(LCHILD(idx), diff, s, MID(s, e), l, r)
    + update_range(RCHILD(idx), diff, MID(s, e) + 1, e, l, r);
}

lld query(int idx, int s, int e, int l, int r) {
  update_lazy(idx, s, e);
  if (r < s || l > e) { return 0; }
  if (l <= s && e <= r) { return seg[idx].value; }
  return query(LCHILD(idx), s, MID(s, e), l, r) + query(RCHILD(idx), MID(s, e) + 1, e, l, r);
}

int main () {
  lld M, K;
  scl(N), scl(M), scl(K);
  for (lld i=1;i<=N;i++) {
    lld a;
    scl(a);
    update_range(1, a, 1, N, i, i);
  }
  for (lld i=0;i<M+K;i++) {
    lld a, b, c;
    lld d;
    scl(a);
    if (a == 1) {
      scl(b), scl(c), scl(d);
      update_range(1, d, 1, N, b, c);
    } else {
      scl(b), scl(c);
      printf("%lld\n", query(1, 1, N, b, c));
    }
  }
  return 0;
}
