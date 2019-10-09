#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
using namespace std;
using vi = vector<int>;
struct edge {
  int a, b, weight;
};

class UnionFind {
    private:
        vi p, rank, sizeSet;
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

class Tree {
  vector<int> now_root;
  vector<pair<int, pair<int, int> > > nodes; // parent, weight, count
  public:
    Tree(int n) {
      now_root.resize(n);
      for(int i=0;i<n;i++){
        now_root[i] = i;
      }
      nodes.assign(n, {-1, {0, 1}});
    }
    void linkNodes(int a, int b, int weight) {
      nodes.push_back({-1 , {weight, nodes[now_root[a]].second.second + nodes[now_root[b]].second.second}});
      nodes[now_root[a]].first = nodes.size() - 1;
      nodes[now_root[b]].first = nodes.size() - 1;
      now_root[a] = nodes.size() - 1;
      now_root[b] = nodes.size() - 1;
    }
    int getDepth(int a) {
      int cur =a;
      int retval = 0;
      while(cur!=-1){
        cur = nodes[cur].first;
        retval ++;
      }
      return retval;
    }
    pair<int, int> getLCA(int a, int b) {
      int depthA = getDepth(a), depthB = getDepth(b);
      int curA = a, curB = b;
      while (curA != curB ) {
        if (depthA > depthB) {
          depthA --;
          curA = nodes[curA].first;
        } else {
          depthB --;
          curB = nodes[curB].first;
        }
      }
      return curA == -1 ? make_pair<int, int>(-1, -1) : nodes[curA].second;
    }
};

int main () {
  int i;
  int n, m;
  sci(n), sci(m);
  vector<edge> edges(m);
  for (i=0;i<m;i++){
    sci(edges[i].a), sci(edges[i].b), sci(edges[i].weight);
    edges[i].a --;
    edges[i].b --;
  }
  sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) -> bool {
    return a.weight < b.weight;
    });
  UnionFind uf(n);
  Tree tr(n);
  for (i=0;i<m;i++){
    if (!uf.isSameSet(edges[i].a, edges[i].b)) {
      uf.unionSet(edges[i].a, edges[i].b);
      tr.linkNodes(edges[i].a, edges[i].b, edges[i].weight);
    }
  }
  int Q;
  int a, b;
  sci(Q);
  for(i=0;i<Q;i++){
    sci(a), sci(b);
    a--, b--;
    auto r = tr.getLCA(a, b);
    if(r.first == -1) printf("-1\n");
    else printf("%d %d\n", r.first, r.second);
  }
  return 0;
}
