#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define sci(N) scanf("%d", &(N))
#define MAX_V 410
using namespace std;

int N, P;
int a, b;
using vi = vector<int>;
class NetworkFlow {
private:
  struct edge {
    int dest, invi, fl;
  };

  int vn;
  vi lv;
  const static int INF = numeric_limits<int>::max();
  vector< vector<edge> > edges;

public:
  NetworkFlow (int n)
    : vn(n), lv(vn), edges(vn)
  {}

  void addEdge(int s, int d, int f) {
    edge x{ d, (int)edges[d].size(), f};
    edge y{ s, (int)edges[s].size(), 0};

    edges[s].push_back(x);
    edges[d].push_back(y);
  }

  bool bfsv(int s, int d)
  {
    int i;
    int nv, nlv;

    fill(lv.begin(), lv.end(), 0);

    lv[s] = 1;
    queue<int> q;
    q.push(s);

    while (!q.empty()){
      nv = q.front();
      q.pop();
      nlv = lv[nv];

      for (const auto& e: edges[nv]) {
        if (e.fl > 0 && lv[e.dest] == 0) {
          lv[e.dest] = nlv + 1;
          q.push(e.dest);
          if (e.dest == d) return true;
        }
      }
    }
    return false;
  }

  int flowing(int s, int d, int f) {
    if (s == d) return f;
    int nf;

    for (auto &e : edges[s]) {
      if (e.fl > 0 && lv[e.dest] == lv[s] +1) {
        nf = flowing(e.dest, d, min(f, e.fl));
        if (nf > 0) {
          edge &ei = edges[e.dest][e.invi];
          e.fl -= nf;
          ei.fl += nf;
          return nf;
        }
      }
    }
    return 0;
  }

  int solve (int s, int d) {
    int res = 0;
    int nres;
    
    while (bfsv(s, d)) {
      while (true) {
        nres = flowing(s, d, INF);
        if (nres == 0) break;
        res += nres;
      }
    }
    
    return res;
  }
};


int main () {
  sci(N), sci(P);

  NetworkFlow nf (N+1);
  for (int i = 0; i < P; i ++) {
    sci(a), sci(b);
    nf.addEdge(a, b, 1);
  }

  printf("%d", nf.solve(1, 2));

  return 0;
}
