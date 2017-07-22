#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector< pair<int, int> > Jewelry;
    int N, K, M, V, sum=0;
    vector<int> C;
    scanf("%d %d", &N, &K);
    for(int i =0;i<N;i++){
        scanf("%d %d", &M, &V);
        Jewelry.push_back(make_pair(M,V));
    }
    for(int i=0;i<K;i++){
        int j;
        scanf("%d", &j);
        C.push_back(j);
    }

    sort(Jewelry.begin(), Jewelry.end(), [](pair<int, int> x1, pair<int, int> x2) -> bool{
        if(x1.second==x2.second) return x1.first<x2.first;
        return x1.second>x2.second;
    });
    sort(C.begin(), C.end(), [](int x1, int x2) -> bool{
        return x1<x2;
    });

    for(int i =0;i<N;i++){
        printf("%d %d\n", Jewelry[i].first, Jewelry[i].second);
    }
    for(int i =0;i<K;i++){
        printf("%d\n", C[i]);
    }
    for(int i=0, j;i<K;i++){
        j=0;
        if(C[j]>Jewelry[i].first) {
            sum += Jewelry[i].second;
            C.erase(C.begin() +j);
        }
    }
    printf("%d", sum);


    return 0;
}