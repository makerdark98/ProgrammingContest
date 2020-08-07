#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct seg_tree {
  int sz = 1 << 21, bs = 1 << 20;
  int data[1 << 21];

  void update(int x, int v) {
    x |= bs;
    data[x] = v;
    while (x > 1) {
      x >>= 1;
      data[x] = min(data[x * 2], data[x * 2 + 1]);
    }
  }

  int query(int s, int e) {
    s |= bs;
    e |= bs;
    int retval = 1e9;
    while (s < e) {
      if (s & 1) retval = min(retval, data[s++]);
      if (e & ~1) retval = min(retval, data[e--]);
      s >>= 1;
      e >>= 1;
    }
    if (s == e) retval = min(retval, data[s]);
    return retval;
  }
}seg;

void suffix(const char* s, int *sa) {
  int n = strlen (s);
  vector<int> g(n+1), nextg(n+1);
  int base;

  auto cmp = [&s, &n, &g, &base](const int& a, const int& b) -> bool {
    return g[a] == g[b] ? g[a + base] < g[b + base] : g[a] < g[b];
  };

  for (int i = 0; i < n; i ++) {
    sa[i] = i;
    g[i] = s[i] - 'A';
  }

  g[n] = -1;
  for (base = 1; base <= n; base <<= 1) {
    sort (sa, sa + n, cmp);

    nextg[sa[0]] = 0;
    for (int i = 1; i < n; i ++) {
      if (cmp(sa[i - 1], sa[i])) {
        nextg[sa[i]] = nextg[sa[i-1]] + 1;
      } else {
        nextg[sa[i]] = nextg[sa[i-1]];
      }
    }

    for (int i = 0 ;i < n; i ++) {
      g[i] = nextg[i];
    }
  }
}

void lcp(const char* s, const int *sa, int* l) {
  int n = strlen(s);
  vector<int> r(n + 1);
  for (int i = 0; i < n; i ++)
    r[sa[i]] = i;

  for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
    if (r[i] == n - 1) continue;
    for (int j = sa[r[i] + 1]; s[i +k] !='&' && s[i + k] == s[j + k]; k ++)
      ;
    l[r[i]] = k;
  }
}



#define SIZE 1000010

char S[SIZE];
int pos[12];
int SA[SIZE], L[SIZE];
int origin[SIZE];
int cnt[12];

int n, m;
int N;
bool check() {
  for (int i = 1; i <= N; i ++) 
    if (!cnt[i]) return false;
  return true;
}
int main () {
  pos[0] = 0;
  scanf("%d", &N);
  for (int i = 1 ; i <= N ; i ++) {
    scanf(" %s", S + pos[i]);
    n = strlen(S + pos[i]);
    S[pos[i] + n] = '&';
    pos[i + 1] = pos[i] + n + 1;
    fill(origin + pos[i], origin + pos[i+1] - 1, i);
  }

  suffix(S, SA);
  lcp(S, SA, L);
  set<int> s;
  int x = 0, i;
  int result = 0; /* [x, i) */
  for (i = 0; i < pos[N + 1]; i ++) {
    seg.update(i, L[i]);
    cnt[origin[SA[i]]] ++;
    while (x <= i && check()) {
      result = max(result, seg.query(x, i - 1));
      cnt[origin[SA[x]]] --;
      x ++;
    }
  }
  while (x <= i && check()) {
    result = max(result, seg.query(x, i - 1));
    cnt[origin[SA[x]]] --;
    x ++;
  }

  printf("%d", result);

  return 0;
}
