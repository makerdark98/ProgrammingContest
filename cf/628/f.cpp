#include <iostream>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
using namespace std;

int n, m;
int a, b;
vector<vector<int> > edges;
vector<bool> visited;
vector<int> node;
int result;
vector<int> result_set;
void dfs(int idx);
int getMinimumValue(int idx);
int main () {
  sci(n), sci(m);
  edges.resize(n+1);
  visited.assign(n+1, false);
  node.assign(n+1, -1);
  for (int i=0;i<m;i++) {
    sci(a), sci(b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  node[1] = 1;
  dfs(1);

  printf("%d\n", result);
  for (int i=0;i<result_set.size();i++) {
    printf("%d ", result_set[i]);
  }

  return 0;
}
void dfs(int idx) {
  visited[idx] = true;
  node[idx] = getMinimumValue(idx);
  for (int i=0;i<edges[idx].size();i++) {
    if (!visited[edges[idx][i]]) {
      dfs(edges[idx][i]);
    } else {
      // edges[idx][i] 에 값 추가
      node[idx] = getMinimumValue(idx);
    }
  }
}
