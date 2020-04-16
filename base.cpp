#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%lld ", (n))
using namespace std;
using lld = long long;
using pii = pair<lld, lld>;
using vi = vector<lld>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using base = complex<double>;

/* Fast Fourier transform */
void fft(vector<base> &a, bool invert) {
    int n = a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
/* Fast Multiply Using FFT */
void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res) {
    vector <base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(),b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

/* Union Find Implementation class (Forest) */
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


/*  Fast dijkstra Algorithm Using set with adjcent egde graph */
struct edge {
    lld to, length;
};
vvi route;

lld dijkstra(const vector< vector<edge> > &graph, lld source, lld target) {
    vi min_distance(graph.size(), LLONG_MAX);
    min_distance[source] = 0;
    set<pii> active_vertices;
    active_vertices.insert( {0, source} );
    while (!active_vertices.empty()) {
        int where = active_vertices.begin() -> second;
        if (where == target) return min_distance[where];
        active_vertices.erase(active_vertices.begin());
        for (auto ed : graph[where] ) {
            if (min_distance[ed.to] > min_distance[where] + ed.length ||
                    (min_distance[ed.to] == min_distance[where] + ed.length &&
                     route[ed.to].size() > route[ed.to].size() +1)) {
                active_vertices.erase({min_distance[ed.to], ed.to});
                route[ed.to] = route[where];
                route[ed.to].push_back(where);
                min_distance[ed.to] =  min_distance[where] + ed.length;
                active_vertices.insert({min_distance[ed.to], ed.to});
            }
        }
    }
    return min_distance[target];
}

/*  KMP ALgorithm Implementation */
void calculate_pi(vi& pi, const vector<char>& str) {
    pi[0] = -1;
    for(int i=1, j=-1;i<str.size();i++) {
        while(j>=0&&str[i]!=str[j+1]) j =pi[j];
        if(str[i]==str[j+1]) pi[i] = ++j;
        else pi[i]=-1;
    }
}
vi kmp(const vector<char>& text, const vector<char>& pattern) {
    vi pi(pattern.size()), ans;
    if (pattern.size()==0) return ans;
    calculate_pi(pi, pattern);
    for(int i=0,j=-1;i<text.size();i++) {
        while(j>=0 && text[i]!=pattern[j+1]) j=pi[j];
        if(text[i]==pattern[j+1]){
            j++;
            if(j+1==pattern.size()) {
                ans.push_back(i-j);
                j=pi[j];
            }
        }
    }
    return ans;
}

/*  Segment Tree For Partial Sum */
#define mid(s, e) (((s) + (e)) / 2)
class SegmentTree {
    private:
    vi st, data;
    int rsq(int ss, int se, int qs, int qe, int si) {
        if (qs <= ss && qe >= se) return st[si];
        if (se < qs || ss > qe) return 0;

        return rsq(ss, mid(ss, se), qs, qe, 2*si+1) +
            rsq(mid(ss, se)+1, se, qs, qe, 2*si+2);
    }

    void update(int ss, int se, int i, int diff, int si) {
        if (i < ss || i > se) return;
        st[si] = st[si] + diff;

        if (se != ss) {
            update(ss, mid(ss, se), i, diff, 2 * si + 1);
            update(mid(ss, se) + 1, se, i, diff, 2 * si + 2);
        }
    }
    public:
    SegmentTree(vi _data) {
        data = _data;
        int x = (int)(ceil(log2(data.size())));
        int max_size = 2*(int)pow(2, x) -1 ;
        st.assign(max_size, 0);

        build(0, data.size() - 1, 0);
    }

    void updateValue(int i, int v) {
        if (i < 0 || i >= data.size()) {
            return;
        }
        int diff = v - data[i];
        data[i] = v;
        update(0, data.size()-1, i, diff, 0);
    }

    int rsq(int qs, int qe) {
        if (qs < 0 || qe > data.size()-1 || qs > qe) {
            return -1;
        }
        return rsq(0, data.size()-1, qs, qe, 0);
    }

    int build(int ss, int se, int si) {
        if (ss == se) {
            st[si] = data[ss];
            return data[ss];
        }

        st[si] = build(ss, mid(ss, se), si*2+1) +
            build(mid(ss, se) +1, se, si*2 +2 );
        return st[si];
    }

    int size() {
        return data.size();
    }
};

/*  FenwickTree  */
#define LSOne(S) ((S) & (-(S)))
class FenwickTree {
    private:
        vi ft;
    public:
        FenwickTree(int n) {
            ft.assign(n+1, 0);
        }

        int rsq(int b) {
            int sum = 0;
            for(;b;b-=LSOne(b)) sum += ft[b];
            return sum;
        }

        int rsq(int a, int b) {
            return rsq(b) - ((a ==1 || a==0) ? 0 : rsq(a-1));
        }

        void adjust(int k, int v) {
            if (k >= (int)ft.size()) {
                ft.resize(k+1, 0);
                int remain = k - LSOne(k);
                int a = LSOne(k)-1;
                for(;a;a-=LSOne(a)) {
                    ft[k] += ft[remain+a];
                }
                ft[k] += v;
                return;
            }

            for(; k< (int)ft.size(); k+=LSOne(k)) {
                ft[k] += v;
            }
        }

        void update(int k, int v) {
            if (k >= (int)ft.size()) adjust(k, v);
            else adjust(k, v-rsq(k, k));
        }
};

class NetworkFlow {
private:
  struct edge {
    int dest, invi, fl;
  };

  int vn;
  vi lv;
  vi bfsq;
  int bfsqt;
  const static int INF = numeric_limits<int>::max();
  vector< vector<edge> > edges;

public:
  NetworkFlow (int n)
    : vn(n), lv(vn), bfsq(vn), edges(vn)
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
    bfsq[0] = s;
    bfsqt++;

    for (i = 0; i < bfsqt; i++) {
      nv = bfsq[i];
      nlv = lv[nv];

      for (const auto& e: edges[nv]) {
        if (e.fl > 0 && lv[e.dest] == 0) {
          lv[e.dest] = nlv + 1;
          bfsq[bfsqt++] = e.dest;
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


int main() {
    return 0;
}
