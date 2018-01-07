#include <iostream>
#include <queue>
using namespace std;

#define sci(n) scanf("%d", &(n))
int forest[502][502];
int dp[502][502];
int maxi=0;
int n;
using pii=pair<int, int>;
using piii=pair<int, pii>;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x, int y, int val){
    if(dp[x][y]>=val) return;
    dp[x][y]=val;
    if(maxi<val) maxi=val;
    for(int i=0;i<4;i++){
        if(forest[x+dx[i]][y+dy[i]]>forest[x][y]){
            dfs(x+dx[i],y+dy[i],val+1);
        }
    }
}

int main(){
    sci(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sci(forest[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dfs(i,j,1);
    printf("%d\n",maxi);
    return 0;
}
