#include <iostream>
#include <vector>
using namespace std;
#define sci(n) scanf("%d", &(n))
#define SIZE 100000
using vi = vector<int>;

int tree[SIZE * 4];
void update(int idx, int diff) {
  if (idx <= 0) return;
  tree[idx] += diff;
  update(idx>>1, diff);
}
int query(int s, int e) {
  int retval = 0;
  if (s > e) return 0;
  if (s == e) return tree[s];

  if (s % 2 == 1) retval += tree[s++];
  if (e % 2 == 0) retval += tree[e--];
  retval += query (s/2, e/2);
  return retval;
}

int search (int val, int base) {
  int s = base, e = base * 2 - 1;
  int m;

  while (s < e) {
    m = (s + e) / 2;
    int t = query (base, m);
    if (t < val) s = m + 1;
    else e = m;
  }

  return e;
}
int main () {
  int N, K;
  sci(N), sci(K);
  vi data(N);
  for(int i=0;i<N;i++) sci(data[i]);

  int base;
  for (base = 1; base < SIZE; base <<= 1);
  
  for (int i=0;i<K-1;i++) update (base + data[i], 1);

  long long result = 0;
  for (int i=K-1;i<N;i++) {
    update (base + data[i], 1);
    result += (search ((K+1)/2, base) - base);
    update (base + data[i-K+1], -1);
  }

  printf("%lld", result);

  return 0;
}
