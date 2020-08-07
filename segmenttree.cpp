#include <iostream>
#include <vector>
using namespace std;
#define IDX_SIZE (1 << 21)
#define IDX_BASE (IDX_SIZE >> 1)

/* min tree */
struct index_tree {
  int sz = IDX_SIZE, bs = IDX_BASE;
  int node[IDX_SIZE];

  void update(int x, int v) {
    x |= bs;
    node[x] = v;
    while (x > 1) {
      x >>= 1;
      node[x] = min(node[x * 2], node[x * 2 + 1]);
    }
  }

  int query(int s, int e) {
    s |= bs;
    e |= bs;
    int retval = 1e9;
    while (s < e) {
      if (s & 1) retval = min(retval, node[s++]);
      if (e & ~1) retval = min(retval, node[e--]);
      s >>= 1;
      e >>= 1;
    }
    if (s == e) retval = min(retval, node[s]);
    return retval;
  }
};


using lld = long long;
#define SEG_SIZE 1 << 18
struct node_t {
  lld value, lazy;
};

/* sum tree */
struct seg_tree {
  node_t node[4 * SEG_SIZE];
  
  lld build(lld* d, lld idx, lld s, lld e) {
    if (s == e) return node[idx].value = d[s];
    return node[idx].value = build(d, idx * 2, s, (s + e) / 2) + build(d, idx * 2 + 1, (s + e) / 2 + 1, e);
  }

  void update_lazy(lld idx, lld s, lld e) {
    if (node[idx].lazy != 0) {
      node[idx].value += (e - s + 1) * node[idx].lazy;
      if (s != e) {
        node[idx * 2].lazy += node[idx].lazy;
        node[idx * 2 + 1].lazy += node[idx].lazy;
      }
      node[idx].lazy = 0;
    }
  }

  lld update_range(lld idx, lld diff, lld s, lld e, lld l, lld r) {
    update_lazy(idx, s, e);
    if (r < s || l > e) return node[idx].value;
    if (l <= s && e <= r) {
      node[idx].lazy += diff;
      update_lazy(idx, s, e);
      return node[idx].value;
    }
    return node[idx].value = 
      update_range(idx * 2, diff ,s, (s + e) / 2, l, r) + update_range(idx * 2 + 1, diff, (s + e) / 2 + 1, e, l, r);
  }

  lld query(lld idx, lld s, lld e, lld l, lld r) {
    update_lazy(idx, s, e);
    if (r < s || l > e) return 0;
    if (l <= s && e <= r) return node[idx].value;
    return query(idx * 2, s, (s + e)/ 2, l, r) + query(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
  }
}seg;

#define scl(N) scanf("%lld", &(N))

int main () {
  lld N, M, K;
  scl(N), scl(M), scl(K);
  for (lld i = 1; i <= N; i++) {
    lld a;
    scl(a);
    seg.update_range(1, a, 1, N, i, i);
  }

  for (lld i = 0; i < M + K; i ++) {
    lld a, b, c;
    lld d;
    scl(a);
    if (a == 1) {
      scl(b), scl(c), scl(d);
      seg.update_range(1, d, 1, N, b, c);
    } else {
      scl(b), scl(c);
      printf("%lld\n", seg.query(1, 1, N, b, c));
    }
  }
  return 0;
}
