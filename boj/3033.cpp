#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

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
    if (r[i] == n -1) continue;
    for (int j = sa[r[i] + 1]; s[i + k] == s[j + k]; k ++)
      ;
    l[r[i]] = k;
  }
}

#define SIZE 200010

char S[SIZE];
int SA[SIZE], L[SIZE];

int main () {
  int n;
  scanf("%d", &(n));
  scanf(" %s", S);
  suffix(S, SA);
  lcp(S, SA, L);
  vector<int> r(n + 1);
  for (int i = 0; i < n; i ++)
    r[SA[i]] = i;

  int result = 0;
  for (int i = 0; i < n - 1; i ++) {
    result = max (result, L[SA[i]]);
  }
  printf("%d", result);
  return 0;
}
