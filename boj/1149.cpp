#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
vector<long long> col_cost[3];
vector<long long> cost[3];
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<3;i++){
        col_cost[i].assign(N+1,0);
        cost[i].resize(N+1);
    }
    for(int i=1;i<=N;i++){
        scanf("%lld %lld %lld", &cost[0][i], &cost[1][i], &cost[2][i]);
    }
    for(int i=1;i<=N;i++){
        col_cost[0][i] = min(col_cost[1][i-1], col_cost[2][i-1]) + cost[0][i];
        col_cost[1][i] = min(col_cost[0][i-1], col_cost[2][i-1]) + cost[1][i];
        col_cost[2][i] = min(col_cost[1][i-1], col_cost[0][i-1]) + cost[2][i];
    }
    long long m=10e9;
    for(int i=0;i<3;i++){
        m=min(m, col_cost[i][N]);
    }
    printf("%lld",m);
    return 0;
}
