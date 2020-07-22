#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define sci(N) scanf("%d", &(N))
vector<int> edges[100010];
int discovery[100010];
int discovery_count;
vector<pair<int, int>> result;

int dfs (int idx, int parent) {
  discovery[idx] = ++ discovery_count;

  int retval = discovery[idx];
  for (int i = 0; i < edges[idx].size(); i ++) {
    if (!discovery[edges[idx][i]]) {
      int low = dfs(edges[idx][i], idx);
      if (low > discovery[idx])
        result.push_back({min(idx, edges[idx][i]), max(idx, edges[idx][i])});
      retval = min (retval, low);
    } else if(edges[idx][i] != parent) {
      retval = min (retval, discovery[edges[idx][i]]);
    }
  }

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

  for (int i = 1; i <= V; i ++)
    if (!discovery[i]) dfs(i, 0);

  sort(result.begin(), result.end());
  printf("%d\n", (int)result.size());
  for (int i = 0; i < result.size(); i ++)
    printf("%d %d\n", result[i].first, result[i].second);
  return 0;
}
