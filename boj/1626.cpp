#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define sci(N) scanf("%d", &(N))
#define scl(N) scanf("%lld", &(N))
using namespace std;
using lld = long long;
struct edge_t {
  lld a, b, cost, idx;
};
vector<edge_t> edges;

int N, M;
#define MAX_V 200010
#define MAX_E 200010

lld parent[MAX_V];
bool visited[MAX_V];
lld set_size[MAX_V];
lld depth[1 << 18];
lld par[18][1 << 18];
lld maxEdge[18][1 << 18];
lld maxSecondEdge[18][1 << 18];
bool useEdge[MAX_E];
vector<vector<pair<lld, lld >>> tree_edges;
void init(lld N) {
  for (lld i = 0; i <= N; i ++) {
    parent[i] = i;
    set_size[i] = 1;
  }
}

lld getParent(lld a) { return parent[a] == a ? a : parent[a] = getParent(parent[a]); }
bool isSameGroup(lld a, lld b) { return getParent(a) == getParent(b); }
void merge(lld a, lld b) {
  lld pa = getParent(a), pb = getParent(b);
  lld np = set_size[pa] < set_size[pb] ? pa : pb;
  lld nc = set_size[pa] < set_size[pb] ? pb : pa;
  set_size[np] += set_size[nc];
  parent[nc] = np;
}

lld lca(lld s, lld e){
  if(depth[s] > depth[e]) swap(s, e);
  lld dx = depth[e] - depth[s];
  for(lld i = 0; i < 18; i++){
    if((dx >> i) & 1) e = par[i][e];
  }
  for(lld i = 17; i >= 0; i--){
    if(par[i][s] != par[i][e]){
      s = par[i][s];
      e = par[i][e];
    }
  }
  if(s == e) return s;
  return par[0][s];
}

lld getMaxEdge(lld s, lld level, lld except) {
  if (level < 0) return -1;
  if (level == 0 && maxEdge[0][s] != except) return maxEdge[0][s];
  lld base = log2(level);
  int tmp[3];
  tmp[0] = getMaxEdge(par[base][s], level - (1 << base), except);
  tmp[1] = maxEdge[base][s];
  tmp[2] = maxSecondEdge[base][s];
  sort(tmp, tmp + 3);
  int k;
  for (k = 2; k > 0 && tmp[k] == except; k--)
    ;
  return tmp[k];
}

void dfs(lld idx) {
  visited[idx] = true;
  for (auto& edge: tree_edges[idx]){
    lld& to = edge.first;
    lld& cost = edge.second;
    if (!visited[to]) {
      depth[to] = depth[idx] + 1;
      par[0][to] = idx;
      maxEdge[0][to] = cost;
      maxSecondEdge[0][to] = -1;
      dfs(to);
    }
  }
}

int main () {
  sci(N), sci(M);
  lld a, b, c;
  for (lld i = 0; i < M; i ++) {
    scl(a), scl(b), scl(c);
    edges.push_back({a, b, c, i});
  }
  sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b) -> bool { return a.cost < b.cost; });

  long long mst_value = 0;
  init(N);
  tree_edges.resize(N + 1);
  for (auto& edge: edges) {
    if (isSameGroup(edge.a, edge.b)) continue;

    useEdge[edge.idx] = true;
    tree_edges[edge.a].push_back({edge.b, edge.cost});
    tree_edges[edge.b].push_back({edge.a, edge.cost});
    merge(edge.a, edge.b);
    mst_value += edge.cost;
  }

  for (lld i = 1; i < N; i++) {
    if (!isSameGroup(i, i+1)) {
      printf("-1");
      return 0;
    }
  }

  depth[1] = 1;
  for (lld i = 1; i <= N; i ++)
    if (!visited[i]) dfs(i);
  for (lld i = 1; i <= 17; i ++) {
    for (lld j = 1; j <= N; j++) {
      par[i][j] = par[i-1][par[i-1][j]];
      maxEdge[i][j] = max(maxEdge[i-1][par[i-1][j]], maxEdge[i-1][j]);
      int tmp[4];
      tmp[0] = maxEdge[i-1][par[i-1][j]];
      tmp[1] = maxEdge[i-1][j];
      tmp[2] = maxSecondEdge[i-1][par[i-1][j]];
      tmp[3] = maxSecondEdge[i-1][j];
      sort(tmp, tmp + 4);
      int k = 2;
      while (k >= 0 && tmp[k] == tmp[k+1])
        k--;
      maxSecondEdge[i][j] = tmp[k];
    }
  }
  

  sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b) -> bool { return a.idx < b.idx; });

  long long result = mst_value;
  for (auto& edge: edges) {
    if (!useEdge[edge.idx]) {
      if (edge.a == edge.b) continue;
      lld l = lca(edge.a, edge.b);
      lld a = getMaxEdge(edge.a, depth[edge.a] - depth[l] - 1, edge.cost);
      lld b = getMaxEdge(edge.b, depth[edge.b] - depth[l] - 1, edge.cost);
      if (a == -1 && b == -1) continue;
      long long value = mst_value - max(a, b) + edge.cost;
      result = (value != mst_value && (result == mst_value || result > value)) ? value : result;
    }
  }

  if (result == mst_value) result = -1;
  printf("%lld", result);

  
  return 0;
}
