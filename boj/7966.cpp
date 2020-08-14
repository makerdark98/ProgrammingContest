#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define INF 987654321

void suffix(const char* s, int n, int *sa) {
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

void lcp(const char* s, int n, const int *sa, int* l) {
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

#define SIZE 500500

char S[SIZE];
int SA[SIZE], L[SIZE];
pair<int, int> SAL[SIZE];

int main () {
  scanf(" %s", S);
  int n = strlen(S);
  suffix(S, n, SA);
  lcp(S, n, SA, L);
  vector<int> r(n+1);
  for (int i = 0; i < n; i ++) {
      r[SA[i]] = i;
      SAL[i].first = SA[i];
  }
  
  SAL[r[0]].second = SIZE;
  for (int i = r[0]; i > 0; i --) {
      SAL[i-1].second = min(SAL[i].second, L[i-1]);
  }
  for (int i = r[0]; i < n - 1; i ++) {
      SAL[i+1].second = min(SAL[i].second, L[i]);
  }

  sort(SAL, SAL + n, [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
      return a.second == b.second ? a.first < b.first : a.second > b.second;
  });
  set<int> s;
  multiset<int> ms;
  s.insert(-1);
  s.insert(n);
  ms.insert(n+1);

  int result = n;
  int j = 0;
  for (int i = n - 1; i > 0; i --) {
      while (j < n && SAL[j].second >= i) {
          int a = *(-- s.upper_bound(SAL[j].first - 1));
          int b = *(s.upper_bound(SAL[j].first));
          auto it = ms.find(b-a);
          if (it != ms.end()) ms.erase(it);
          ms.insert(b - SAL[j].first);
          ms.insert(SAL[j].first - a);
          s.insert(SAL[j].first);
          j ++;
      }

      if (!ms.empty() && *ms.rbegin() <= i) {
          result = min(result, i);
      }
  }
  printf("%d", result);
  return 0;
}
