#include <iostream>
#include <vector>
using namespace std;

using lld = long long;
lld V;
vector<vector<pair<lld, lld>>> edges;
vector<bool> visited;
vector<lld> weighted;
lld dfs(int root) {
  lld a=0, b=0;
  for (auto& edge : edges[root]) {
    lld& child = edge.first;
    lld& cost = edge.second;
    if (!visited[child]) {
      visited[child] = true;
      lld t = dfs(child) + cost;
      if (t >= a) { b = a; a = t; }
      else if (t >= b) { b = t;}
    }
  }
  weighted[root] = a + b;
  return a;
}
int main () {
  lld t1;
  lld t2;
  scanf("%lld", &V);
  edges.resize(V+1);
  visited.assign(V+1, false);
  weighted.assign(V+1, 0);
  for (lld i=1;i<=V;i++){
    lld a;
    scanf("%lld", &a);
    while (1) {
      scanf("%lld", &t1);
      if (t1==-1) break;
      scanf("%lld", &t2);
      edges[a].push_back({t1, t2});
    }
  }
  visited[1] = true;
  dfs(1);

  lld result = 0;
  for (lld i=1;i<=V;i++) {
    result = max (result, weighted[i]);
  }
  printf("%lld", result);
  return 0;
}
