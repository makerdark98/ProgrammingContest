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
using namespace std;

int main(){
    int N, M;
    int sum = 0;
    vector<pair<pair<int, int>, int> > edge;
    scanf("%d",&N);
    scanf("%d",&M);
    UnionFind Computer(N+1);
    while(M--){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back(make_pair(make_pair(a,b),c));
    }
    sort(edge.begin(), edge.end(), [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y)->bool{
        return x.second<y.second;
    });
    for(auto ed:edge){
        if(!Computer.isSameSet(ed.first.first,ed.first.second)){
            Computer.unionSet(ed.first.first,ed.first.second);
            sum+=ed.second;
        }
    }
    printf("%d\n",sum);
    return 0;
}