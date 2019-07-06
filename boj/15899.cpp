#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define scl(n) scanf("%lld", &(n))
#define MOD 1000000007LL
using namespace std;
using lld = long long;
using vi = vector<lld>;
using vvi = vector<vi>;
using pii = pair<lld, lld>;
using vpii = vector<pii>;

lld N, M, C;
vvi edges;
lld visited[220000];
lld idx_tree[550000];
vpii nodes, query, range;
lld trav(lld now, lld t) {
  visited[now] ++;
  lld start = t;
  t++;
  for(int i=0;i<edges[now].size();i++){
    if (!visited[edges[now][i]]) 
      t = trav(edges[now][i], t);
  }
  range[now] = {start, t-1};
  return t;
}

void index_inc_up(lld n) {
  if (n==0) return;
  idx_tree[n] ++;
  index_inc_up(n>>1);
}

lld index_query(pii q){
  lld res = 0;
  if (q.first > q.second) return 0;
  if (q.first == q.second) return idx_tree[q.first];
  if (q.first % 2 == 1){
    res += idx_tree[q.first];
    q.first++;
  }
  if (q.second % 2 == 0){
    res += idx_tree[q.second];
    q.second--;
  }
  return res + index_query({q.first/2, q.second/2});
}

int main() {
  scl(N), scl(M), scl(C);
  range.resize(N+1);
  edges.resize(N+1);
  visited.assign(N+1, 0);
  for(lld i=1;i<=N;i++) {
    lld c;
    scl(c);
    nodes.push_back({i, c});
  }

  for(lld i=1;i<N;i++) {
    lld a, b;
    scl(a), scl(b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for(lld i=0;i<M;i++){
    lld v, c;
    scl(v), scl(c);
    query.push_back({v, c});
  }

  auto cmp =  [](const pii& a, const pii& b)->bool {
      if (a.second == b.second) return a.first < b.first;
      return a.second < b.second;
    };
  sort(nodes.begin(), nodes.end(), cmp);
  sort(query.begin(), query.end(), cmp);

  lld base;
  for(base=1;base<N;base<<=1);
  trav(1, base);

  lld node_loop = 0;
  lld query_loop = 0;
  lld result = 0;
  for(lld i=1;i<=N;i++){
    printf("range[%lld] : %lld %lld\n", i, range[i].first, range[i].second);
  }
  for(lld i=1;i<=C;i++){
    while (nodes[node_loop].second <= i && node_loop < N) {
      index_inc_up(range[nodes[node_loop].first].first);
      node_loop ++;
    }

    while (query[query_loop].second <= i && query_loop < M) {
      result += (index_query(range[query[query_loop].first])) %MOD;
      result %= MOD;
      query_loop ++;
    }
  }
  printf("%lld", result);
  return 0;
}
