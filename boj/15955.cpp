#include <iostream>
#include <vector>
#include <algorithm>
#define scl(n) scanf("%lld", &(n))

using namespace std;
using lld = long long;
using pii = pair<lld, lld>;
using vi = vector<lld>;
using vvi = vector<vi>;
using vpii = vector<pii>;

struct route {
  lld from, to, hp;
  bool possible;
};

class UnionFind {
  private:
    vi p, rank, sizeSet;
    lld m_numDisjointSets;
  public:
    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      sizeSet.assign(N, 1);
      m_numDisjointSets = N;
      for (int i = 0; i < N; i++) {
        p[i] = i;
      }
    }
    lld findSet(lld i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(lld i, lld j) {
      return findSet(i) == findSet(j);
    }

    void unionSet(lld i, lld j) {
      if (!isSameSet(i, j)) {
        lld x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) { 
          p[y] = x;
          sizeSet[x] += sizeSet[y];
        }
        else {
          p[x] = y;
          sizeSet[y] += sizeSet[x];
          if (rank[x] == rank[y]) rank[y]++;
        }

        m_numDisjointSets--;
      }
    }

    lld numDisjolldSets() {
      return m_numDisjointSets;
    }

    lld sizeOfSet(lld i) {
      return sizeSet[findSet(i)];
    }
};


int main() {
  lld N, Q;
  vpii check_point;
  vi x_check_point_idx;
  vi y_check_point_idx;
  vector<route> query;
  vector<route> edges;
  vi query_idx;
  scl(N), scl(Q);
  check_point.resize(N);
  UnionFind uf(N);
  x_check_point_idx.resize(N); y_check_point_idx.resize(N);

  query.resize(Q); query_idx.resize(Q);
  for (lld i = 0; i < N; i++) {
    scl(check_point[i].first); scl(check_point[i].second);
    x_check_point_idx[i] = i; y_check_point_idx[i] = i;
  }
  for (lld i = 0; i < Q; i++) {
    scl(query[i].from); scl(query[i].to); scl(query[i].hp);
    query[i].from --; query[i].to --; query_idx[i] = i;
  }

  sort(x_check_point_idx.begin(), x_check_point_idx.end(), 
      [&check_point](const lld& a, const lld& b) -> bool {
        if (check_point[a].first == check_point[b].first) 
          return check_point[a].second < check_point[a].second;
        return check_point[a].first < check_point[b].first;
        });
  for (lld i = 1; i < N; i++){
    edges.push_back({
        .from = x_check_point_idx[i-1],
        .to = x_check_point_idx[i],
        .hp = check_point[x_check_point_idx[i]].first -
        check_point[x_check_point_idx[i-1]].first
        });
  }

  sort(y_check_point_idx.begin(), y_check_point_idx.end(), 
      [&check_point](const lld& a, const lld& b) -> bool {
      if (check_point[a].second == check_point[b].second) 
        return check_point[a].first < check_point[a].first;
      return check_point[a].second < check_point[b].second;
      });
  for (lld i = 1; i < N; i++) {
    edges.push_back({
        .from = y_check_point_idx[i-1],
        .to = y_check_point_idx[i],
        .hp = check_point[y_check_point_idx[i]].second -
        check_point[y_check_point_idx[i-1]].second
        });
  }

  sort(edges.begin(), edges.end(), [](const route& a, const route& b)-> bool {
      return a.hp < b.hp;
      });

  sort(query_idx.begin(), query_idx.end(),
      [&query](const lld& a, const lld& b) -> bool {
        return query[a].hp < query[b].hp;
      });

  lld edges_idx = 0;
  lld qi = 0;

  lld cur_hp;

  while (qi < Q) {
    cur_hp = query[query_idx[qi]].hp;
    while (edges_idx < edges.size() && edges[edges_idx].hp <= query[query_idx[qi]].hp) {
      uf.unionSet(edges[edges_idx].from, edges[edges_idx].to);
      edges_idx ++;
    }

    while (qi < Q && cur_hp == query[query_idx[qi]].hp) {
      query[query_idx[qi]].possible = 
        uf.isSameSet(query[query_idx[qi]].from, query[query_idx[qi]].to);
      qi ++;
    }
  }
  
  for (lld i = 0; i < Q; i++) {
    printf("%s\n", query[i].possible ? "YES" : "NO");
  }

  return 0;
}
