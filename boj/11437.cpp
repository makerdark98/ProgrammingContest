#include <iostream>
#include <vector>
#define sci(n) scanf("%d", &(n))
#define MAX 1e9+7
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
struct spread_position { int s, e; };

int N, M, a, b, base, spread_tree_idx;
vvi tree;
vector<int> spread_tree;
vector<int> depth;
vector<bool> visited;
vector<spread_position> position;

void build(int idx, int depth);
void insert(int position, int idx, int d);
int query(int s, int e);
int lca(int a, int b);

int main () {
  sci(N);
  tree.assign(N+1, vi(0));
  depth.resize(N+1);
  visited.assign(N+1, false);
  position.resize(N+1);

  for (int i=0;i<N-1;i++) { 
    sci(a), sci(b); 
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  for (base = 1; base < 4*N; base <<= 1);

  spread_tree_idx = base;

  spread_tree.assign(base << 1, 0);
  depth[0] = MAX;
  build(1, 1);

  sci(M);

  for (int i=0;i<M;i++){ sci(a), sci(b); printf("%d\n", lca(a, b)); }
  return 0;
}
int lca(int a, int b) {
  if (position[a].s <= position[b].s && position[b].e <=position[a].e) return a;
  else if (position[b].s <= position[a].s && position[a].e <=position[b].e) return b;
  int e = position[a].e > position[b].e ? position[a].s : position[b].s;
  int s = position[a].s < position[b].s ? position[a].e : position[b].e;
  return query(s, e);
}

void build(int idx, int depth) {
  visited[idx] = true;
  position[idx].s = spread_tree_idx;
  insert(spread_tree_idx++, idx, depth);

  for (const auto& child_idx : tree[idx]) {
    if (!visited[child_idx]) {
      build(child_idx, depth+1);
      insert(spread_tree_idx++, idx, depth);
    }
  }

  position[idx].e = spread_tree_idx - 1;
}
void insert(int position, int idx, int d) {
  int beforeValue;
  depth[idx] = d;
  spread_tree[position] = idx;
  
  while (position > 1) {
    position >>= 1;
    beforeValue = spread_tree[position];
    spread_tree[position] = depth[spread_tree[position << 1]] < depth[spread_tree[(position << 1) +1]] ? 
      spread_tree[position << 1] : spread_tree[(position << 1) + 1];

    position = beforeValue == spread_tree[position] ? 1 : position;
  }
}
int query(int s, int e) {
  if (s > e) return 0;
  else if (s == e) return spread_tree[s];
  int retval, r, l;

  l = s % 2 == 1 ? spread_tree[s++] : 0;
  r = e % 2 == 0 ? spread_tree[e--] : 0;

  retval = query (s>>1, e>>1);

  retval = depth[retval] < depth[r] ? retval : r;
  retval = depth[retval] < depth[l] ? retval : l;

  return retval;
}
