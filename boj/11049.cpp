#include <iostream>
#include <limits>
#include <vector>
using namespace std;
#define sci(n) scanf("%d",&(n))
#define MAX numeric_limits<int>::max()
int N;
vector<pair<int, int> > d;
vector<vector<long long> > dp;
long long dfs(int i, int k){
    if(k<i) dp[i][k]=MAX;
    if(k==i) dp[i][k]=0;
    if(dp[i][k]!=-1) return dp[i][k];
    dp[i][k]=MAX;
    for(int j=i;j<N-1;j++){
        dp[i][k]=min(dp[i][k], dfs(i,j)+dfs(j+1,k)+d[i].first*d[j].second*d[k].second);
    }
    return dp[i][k];
}
int main(){
    sci(N);
    d.resize(N);
    dp.resize(N);
    for(int i=0;i<N;i++){
        dp[i].assign(N,-1);
        int a, b;
        sci(a),sci(b);
        d[i].first=a;
        d[i].second=b;
    }
    dfs(0, N-1);
    printf("%lld\n", dp[0][N-1]);
    return 0;
}
