#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
int main(){
    int N, K;
    priority_queue<pair<int,int> >jew;
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++){
        int M, V;
        scanf("%d %d",&M,&V);
        jew.push(make_pair(V,M));
    }
    multiset<int> bag;
    long long sum=0;
    for(int i=0;i<K;i++){
        int C;
        scanf("%d", &C);
        bag.insert(C);
    }
    while(!jew.empty()){
        int V = jew.top().first;
        int M = jew.top().second;
        jew.pop();
        auto tmp = bag.lower_bound(M);
        if (tmp == bag.end())
            continue;
        bag.erase(tmp);
        sum += V;
    }
    printf("%lld\n",sum);
    return 0;
}