#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define sci(N) scanf("%d", &(N))
using namespace std;
struct edge_t {
  int a, b, cost, idx;
};
vector<edge_t> edges;

int N, M;
#define MAX_V 200010
#define MAX_E 200010

int parent[MAX_V];
bool visited[MAX_V];
int set_size[MAX_V];
int depth[1 << 18];
int par[18][1 << 18];
int maxEdge[18][1 << 18];
bool useEdge[MAX_E];
vector<vector<pair<int, int >>> tree_edges;
void init(int N) {
  for (int i = 0; i <= N; i ++) {
    parent[i] = i;
    set_size[i] = 1;
  }
}

int getParent(int a) { return parent[a] == a ? a : parent[a] = getParent(parent[a]); }
bool isSameGroup(int a, int b) { return getParent(a) == getParent(b); }
void merge(int a, int b) {
  int pa = getParent(a), pb = getParent(b);
  int np = set_size[pa] < set_size[pb] ? pa : pb;
  int nc = set_size[pa] < set_size[pb] ? pb : pa;
  set_size[np] += set_size[nc];
  parent[nc] = np;
}

int lca(int s, int e){
  if(depth[s] > depth[e]) swap(s, e);
  int dx = depth[e] - depth[s];
  for(int i = 0; i < 18; i++){
    if((dx >> i) & 1) e = par[i][e];
  }
  for(int i = 17; i >= 0; i--){
    if(par[i][s] != par[i][e]){
      s = par[i][s];
      e = par[i][e];
    }
  }
  if(s == e) return s;
  return par[0][s];
}

int getMaxEdge(int s, int level) {
  if (level < 0) return 0;
  if (level == 0) return maxEdge[0][s];
  int base = log2(level);
  return  max(maxEdge[base][s], getMaxEdge(par[base][s], level - (1 << base)));
}

void dfs(int idx) {
  visited[idx] = true;
  for (auto& edge: tree_edges[idx]){
    int& to = edge.first;
    int& cost = edge.second;
    if (!visited[to]) {
      depth[to] = depth[idx] + 1;
      par[0][to] = idx;
      maxEdge[0][to] = cost;
      dfs(to);
    }
  }
}

int main () {
  sci(N), sci(M);
  int a, b, c;
  for (int i = 0; i < M; i ++) {
    sci(a), sci(b), sci(c);
    edges.push_back({a, b, c, i});
  }
  sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b) -> bool { return a.cost < b.cost; });

  long long mst_value = 0;
  init(N);
  tree_edges.resize(N + 1);
  for (int i = 0; i < edges.size(); i ++) {
    auto& edge = edges[i];
    if (isSameGroup(edge.a, edge.b)) continue;

    useEdge[edge.idx] = true;
    tree_edges[edge.a].push_back({edge.b, edge.cost});
    tree_edges[edge.b].push_back({edge.a, edge.cost});
    merge(edge.a, edge.b);
    mst_value += edge.cost;
  }

  depth[1] = 1;
  for (int i = 1; i <= N; i ++)
    if (!visited[i]) dfs(i);
  for (int i = 1; i <= 17; i ++) {
    for (int j = 1; j <= N; j++) {
      par[i][j] = par[i-1][par[i-1][j]];
      maxEdge[i][j] = max(maxEdge[i-1][par[i-1][j]], maxEdge[i-1][j]);
    }
  }
  

  sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b) -> bool { return a.idx < b.idx; });

  for (int i = 0; i < edges.size(); i ++) {
    if (useEdge[i]) {
      printf("%lld\n", mst_value);
      continue;
    }
    auto& edge = edges[i];
    int l = lca(edge.a, edge.b);
    int a = getMaxEdge(edge.a, depth[edge.a] - depth[l] - 1);
    int b = getMaxEdge(edge.b, depth[edge.b] - depth[l] - 1);
    printf("%lld\n", mst_value - max(a, b) + edge.cost);
  }

  
  return 0;
}
