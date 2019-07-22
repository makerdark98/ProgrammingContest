#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
using namespace std;

struct edge {
  int a, b, w;
};
struct query {
  int a, b;
};
class UnionFind {
    private:
        vector<int> p, rank, sizeSet;
        int m_numDisjointSets;
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
        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i), y = findSet(j);
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

        int numDisjointSets() {
            return m_numDisjointSets;
        }

        int sizeOfSet(int i) {
            return sizeSet[findSet(i)];
        }
};

int main () {
  int n, m;
  int a, b, w;
  sci(n), sci(m);
  vector<edge> edges(m);
  for(int i=0;i<m;i++){
    sci(edges[i].a), sci(edges[i].b), sci(edges[i].w);
    edges[i].a --;
    edges[i].b --;
  }
  sort(edges.begin(), edges.end(), [](const edge& a, const edge& b)->bool{
      return a.w < b.w;
    });
  int Q;
  sci(Q);
  vector<query> queries(Q);
  for(int i=0;i<Q;i++){
    sci(queries[i].a), sci(queries[i].b);
    queries[i].a --;
    queries[i].b --;
  }
  vector<pair<int, int> > result(Q, {-1, -1});
  vector<int> lo(Q, 0), hi(Q, m-1);
  bool isEnd = false;
  while (!isEnd) {
    isEnd = true;
    UnionFind uf(n);
    vector<queue<int> >cond(m);
    for (int i=0;i<Q;i++){
      if (lo[i] <= hi[i]) {
        cond[(lo[i]+hi[i])/2].push(i);
        isEnd = false;
      }
    }
    if(isEnd) break;
    for (int i=0;i<m;i++) {
      uf.unionSet(edges[i].a, edges[i].b);
      while(!cond[i].empty()) {
        auto f = cond[i].front();
        cond[i].pop();
        if (uf.isSameSet(queries[f].a, queries[f].b)) {
          result[f] = {edges[i].w, uf.sizeOfSet(queries[f].a)};
          hi[f] = i-1;
        } else {
          lo[f] = i+1;
        }
      }
    }
  }

  for(int i=0;i<Q;i++){
    if(result[i].first == -1) printf("-1\n");
    else printf("%d %d\n", result[i].first, result[i].second);
  }
  return 0;
}
