#include <iostream>
#include <vector>
#include <algorithm>

#define LSOne(x) (x & (-x))

typedef std::vector< std::pair<int, int> > vii;
typedef std::vector<int> vi;

class UnionFind {
private:
    vi parent, rank;
public:
    UnionFind(int N) {              //총 N개의 Vertex가 있음
        rank.assign(N, 0);
        parent.assign(N, 0);
        for (int i = 0; i < N; i++) parent[i] = i;
    }
    int findSet(int i){
        return (parent[i]==i) ? i : (parent[i]=findSet(parent[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) parent[y] =x;
            else{
                parent[x] = y;
                if(rank[x]==rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets(){
        int N = rank.size();
        int numSets = N;
        for(int i = 0; i<N; i++) if(parent[i]!=i) numSets--;
    }
    int sizeOfSet(int i){
        int N = rank.size();
        int size = 0;
        for(int j = 0;j<N;j++) if(parent[j]==i) size++;
    }
};

class SegmentTree{
private:
    vi st, A;
    int n;
    int left(int p) {
        return p << 1;
    }
    int right(int p){
        return (p<<1) + 1;
    }
    void build(int p, int L, int R){
        if(L==R) st[p] = L;
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1]<=A[p2]) ? p1: p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j){
        if(i>R|| j<L) return -1;
        if(L>=i&&R<=j) return st[p];

        int p1 = rmq(left(p), L,(L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2+1, R,i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1]<=A[p2]) ? p1 : p2;
    }
public:
    SegmentTree(const vi &_A){
        A = _A;
        n = (int)A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rmq(int i, int j){
        return rmq(1, 0, n-1, i, j);
    }
};

class FenwickTree {
private: vi ft;
public: FenwickTree(int n){ft.assign(n+1, 0)}
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) -(a==1 ? 0: rsq(a-1));}
    void adjust(int k, int v){
        for(; k<(int)ft.size();k+=LSOne(k)) ft[k] +=v;}
};

