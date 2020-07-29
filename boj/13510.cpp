#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9+7
#define SIZE 100010
#define sci(N) scanf("%d", &(N))
using namespace std;
struct edge_t {
  int to, cost;
};
struct edge_t2 {
  int a, b, cost;
};
struct seg{
	int tree[270000], lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void update(int x, int v){
		x += lim;
		tree[x] = v;
		while(x > 1){
			x >>= 1;
			tree[x] = max(tree[2*x], tree[2*x+1]);
		}
	}
	int query(int s, int e){
		s += lim;
		e += lim;
		int ret = -1e9;
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++]);
			if(e%2 == 0) ret = max(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
}seg;

int sz[SIZE], parent[17][SIZE], depth[SIZE], heavy[SIZE], in[SIZE], out[SIZE], costs[SIZE], top[SIZE];
vector<edge_t> edges[SIZE];
int current;
void dfs1(int v) {
    sz[v] =1;
    for (edge_t& edge : edges[v]) {
        int to = edge.to;
        int cost = edge.cost;
        if (parent[0][v] == to) continue;
        parent[0][to] = v;
        depth[to] = depth[v] + 1;
        costs[to] = cost;
        dfs1(to);
        sz[v] += sz[to];
        if (sz[heavy[v]] < sz[to]) heavy[v] = to;
    }
    sort(edges[v].begin(), edges[v].end(), [](const edge_t& a, const edge_t& b)-> bool {
        return sz[a.to] > sz[b.to];
        });
}

void dfs2(int v){
    in[v] = ++current;
    for (edge_t& edge: edges[v]) {
        int to = edge.to;
        int cost = edge.cost;
        if (parent[0][v] == to) continue;
        top[to] = heavy[v] == to ? top[v] : to;
        dfs2(to);
    }
    out[v] = current;
}

void hld_update(int to, int cost) {
    costs[to] = cost;
    seg.update(in[to], cost);
}

int hld_query(int a, int b) {
    int retval = 0;
    while (top[a] != top[b]) {
        retval = max (retval, seg.query(in[top[a]], in[a]));
        a = parent[0][top[a]];
    }
    retval = max (retval, seg.query(in[b] + 1, in[a]));
    return retval;
}

int lca(int s, int e){
	if(depth[s] > depth[e]) swap(s, e);
	int dx = depth[e] - depth[s];
	for(int i=0; i<17; i++){
		if((dx >> i) & 1) e = parent[i][e];
	}
	for(int i=16; i>=0; i--){
		if(parent[i][s] != parent[i][e]){
			s = parent[i][s];
			e = parent[i][e];
		}
	}
	if(s == e) return s;
	return parent[0][s];
}

int main() {
  int N, M;
  sci(N);
  vector<edge_t2> graphs;
  for (int i = 1; i < N; i ++) {
    int u, v, w;
    sci(u), sci(v), sci(w);
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
    graphs.push_back({ u, v, w });
  }
  depth[1] = 1;
  top[1] = 1;
  
  dfs1(1);
  dfs2(1);
  
  seg.init(N);
  for (int i=2; i<= N; i++) {
      seg.update(in[i], costs[i]);
  }
  for(int i=1; i<=16; i++){
      for(int j=1; j<=N; j++){
	    parent[i][j] = parent[i-1][parent[i-1][j]];
	}
  }

  sci (M);
  for (int i = 0; i < M; i ++) {
    int a, b, c;
    sci(a), sci(b), sci(c);
    if (a == 1) {
      b--;
      int from = graphs[b].a, to = graphs[b].b;
      if (depth[from] > depth[to]) swap(from, to);
      hld_update(to, c);
    } else {
      int l = lca(b, c);
      printf("%d\n", max(hld_query(b, l), hld_query(c, l)));
    }
  }

  return 0;
}
