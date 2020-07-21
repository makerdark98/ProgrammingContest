#include <iostream>
#include <vector>
using namespace std;
#define sci(N) scanf("%d", &(N))

int count;
int counts[10010];
vector<int> edges[10010];
bool isCut[10010];

int dfs(int idx, bool isRoot) {
  counts[idx] = ++count;

  int retval = counts[idx];
  int children = 0;
  for (const auto& to: edges[idx]) {
    if (!counts[to]) {
      children ++;
      int low = dfs(to, false);
      if (!isRoot && low >= counts[idx]) isCut[idx] = true;
      retval = min (retval, low);
    } else {
      retval = min (retval, counts[to]);
    }
  }

  if (isRoot && children >= 2) isCut[idx] = true;
  return retval;
}

int main () {
  int V, E;
  sci(V), sci(E);

  for (int i = 0; i < E; i ++) {
    int a, b;
    sci(a), sci(b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 1; i <= V; i ++) {
    if (!counts[i]) dfs(i, true);
  }
  int result = 0;
  for (int i = 1; i <= V; i ++) {
    if (isCut[i]) result ++;
  }
  printf("%d\n", result);
  for (int i = 1; i <= V; i ++) {
    if (isCut[i]) printf("%d ", i);
  }

  return 0;
}
