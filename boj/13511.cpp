#include <iostream>
#include <vector>
#include <queue>
#define sci(n) scanf("%d", &(n))
#define MAX 1e9+7
#define SIZE 100010
using namespace std;
using lld = long long;
using ii = pair<lld, lld>; using vi = vector<lld>; using vii = vector<ii>; using vvii = vector<vii>;
struct node { int s, e, depth; lld dist; bool visited; vii edges; int ancestor[50];};
int N, M, u, v, w, q, k, base, baseIdx;
int tree[8*SIZE];
node nodes[SIZE];
lld result;
void build(int idx, int depth);
void update(int idx, int val);
int query(int s, int e);
lld query1(int a, int b);
void build_ancestor();
lld query2(int a, int b, int k);
int getParent(int a, int wanted_k);
int main () {
  sci(N);
  for(int i=0;i<N-1;i++) {
    sci(u), sci(v), sci(w);
    nodes[u].edges.push_back({v, w});
    nodes[v].edges.push_back({u, w});
  }

  for (base = 1; base < 2 * N; base <<= 1) ;

  baseIdx = base;

  nodes[0].depth = MAX;
  nodes[1].ancestor[0] = 0;
  nodes[0].ancestor[0] = 0;
  nodes[1].dist = 0;

  build(1, 1);
  build_ancestor();

  sci(M);
  for(int i=0;i<M;i++) {
    sci(q), sci(u), sci(v);
    if (q == 1) { result = query1(u, v); }
    else { sci(k); result = query2(u, v, k-1); }
    printf("%lld\n", result);
  }

  return 0;
}

void build(int idx, int depth) {
  nodes[idx].visited = true;
  nodes[idx].s = baseIdx;
  nodes[idx].depth = depth;
  update(baseIdx++, idx);

  for (ii& e : nodes[idx].edges) {
    lld& childIdx = e.first;
    lld& weight = e.second;

    if (!nodes[childIdx].visited) {
      nodes[childIdx].ancestor[0] = idx; // ancestor[idx] means 2^idx ancestor idx
      nodes[childIdx].dist = nodes[idx].dist + weight;
      build(childIdx, depth+1);
      update(baseIdx++, idx);
    }
  }

  nodes[idx].e = baseIdx - 1;
}

void update(int position, int val) {
  tree[position] = val;
  while (position > 1) {
    position >>= 1;
    int left = tree[position << 1];
    int right = tree[(position << 1) + 1];
    tree[position] = nodes[left].depth < nodes[right].depth ? left : right;
  }
}

int lca(int a, int b){
  int s, e;
  if (nodes[a].s <= nodes[b].s && nodes[b].e <= nodes[a].e) return a;
  else if (nodes[b].s <= nodes[a].s && nodes[a].s <= nodes[b].e) return b;
  else {
    s = nodes[a].s < nodes[b].s ? nodes[a].e : nodes[b].e;
    e = nodes[a].e > nodes[b].e ? nodes[a].s : nodes[b].s;
    return query(s, e);
  }
}

int query(int s, int e) {
  if (s == e) return tree[s];
  else if (s > e) return 0;
  int retval, r = 0, l = 0;
  if (s % 2 == 1) r = tree[s++];
  if (e % 2 == 0) l = tree[e--];
  retval = query(s >> 1, e >> 1);

  retval = nodes[r].depth < nodes[retval].depth ? r : retval;
  retval = nodes[l].depth < nodes[retval].depth ? l : retval;

  return retval;
}

lld query1(int a, int b) {
  int l = lca(a, b);
  return nodes[a].dist + nodes[b].dist - 2 * nodes[l].dist;
}

void build_ancestor() {
  queue<ii> q;
  for(int i=1;i<=N;i++){
    q.push({i, 0});
  }
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    nodes[f.first].ancestor[f.second+1] = 
      nodes[nodes[f.first].ancestor[f.second]].ancestor[f.second];
    if (nodes[f.first].ancestor[f.second+1] != 0) q.push({f.first, f.second + 1});
  }
}

lld query2(int a, int b, int wanted_k) {
  int l = lca(a, b);
  int a_to_l = nodes[a].depth - nodes[l].depth;
  int b_to_l = nodes[b].depth - nodes[l].depth;
  int total = a_to_l + b_to_l;
  return wanted_k <= a_to_l ? getParent(a, wanted_k) : getParent(b, total - wanted_k);
}

int getParent(int a, int wanted_k) {
  if (wanted_k <= 0) return a;
  int idx = 0;
  while ((1 << (idx+1) < wanted_k))
    idx++;
  return getParent(nodes[a].ancestor[idx], wanted_k - (1 << idx));
}
