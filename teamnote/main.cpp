#include <iostream>
#include <vector>
#include <algorithm>

class UnionFind {
private:
    std::vector<int> parent, rank;
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
    std::vector<int> st, A;
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


};

