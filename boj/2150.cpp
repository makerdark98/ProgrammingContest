#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define sci(N) scanf("%d", &(N))
int discovered_s[10010];
pair<int, int> discovered_e[10010];
vector<int> edges[10010];
vector<int> reverse_edges[10010];
bool scc_visited[10010];
vector<vector<int>> scc;
int discover_count;

void dfs(int idx) {
  discovered_s[idx] = ++ discover_count;
  for (int i = 0; i < edges[idx].size(); i ++) {
    if (!discovered_s[edges[idx][i]])
      dfs(edges[idx][i]);
  }
  discovered_e[idx] = {-(++ discover_count), idx};
}

void getSCC(int idx, vector<int>& result) {
  scc_visited[idx] = true;
  result.push_back(idx);
  for (int i = 0; i < reverse_edges[idx].size(); i ++) {
    if (!scc_visited[reverse_edges[idx][i]]) {
      getSCC(reverse_edges[idx][i], result);
    }
  }
}

int main () {
  int V, E;
  sci(V), sci(E);
  for (int i = 0; i < E; i ++) {
    int a, b;
    sci(a), sci(b);
    edges[a].push_back(b);
    reverse_edges[b].push_back(a);
  }

  for (int i = 1; i <= V; i ++)
    if (!discovered_s[i]) dfs(i);

  sort(discovered_e + 1, discovered_e + V + 1);
  for (int i = 1; i <= V; i ++) {
    if (!scc_visited[discovered_e[i].second]) {
      vector<int> data;
      getSCC(discovered_e[i].second, data);
      sort(data.begin(), data.end());
      scc.push_back(move(data));
    }
  }
  sort(scc.begin(), scc.end(), [](const vector<int>& a, const vector<int>& b)-> bool{
      return a.front() < b.front();
      });

  printf("%d\n", (int)scc.size());
  for (int i = 0; i < scc.size(); i ++) {
    for (int j = 0; j < scc[i].size(); j ++) {
      printf("%d ", scc[i][j]);
    }
    printf("-1\n");
  }
  
  return 0;
}
