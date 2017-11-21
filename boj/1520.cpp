#include <iostream>
#include <cstdlib>
using namespace std;
#define sci(n) scanf("%d",&(n))
typedef pair<int, int> pii;
int M,N;
int m[502][502], dp[502][502];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
int dfs(int x, int y){
    if(x==1 && y==1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y]=0;
    for(int i=0;i<4;i++) if(m[x+dx[i]][y+dy[i]]>m[x][y]) dp[x][y]+=dfs(x+dx[i],y+dy[i]);
    return dp[x][y];
}
int main(){
    sci(M), sci(N);
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            sci(m[i][j]);
        }
    }
    dfs(M,N);
    printf("%d\n",dp[M][N]);
    return 0;
}
