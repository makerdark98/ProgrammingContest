#include <iostream>
#include <algorithm>
#include <functional>
#define sci(n) scanf("%d", &(n))
using namespace std;
int N, M;
int d[1002][1002], dp[1002][1002][3];
int dr[] = {0, 0, -1}, dc[] = {1, -1, 0};
int main(){
    sci(N), sci(M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            sci(d[i][j]);
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k]=-999999;
            }
        }
    }
    //0 : down, 1 : left, 2 : right;
    dp[1][1][0]=d[1][1];
    dp[1][1][1]=d[1][1];
    dp[1][1][2]=d[1][1];
    for(int i=2;i<=M;i++){
        dp[1][i][1]=dp[1][i-1][1]+d[1][i];
    }
    for(int i=2;i<=N;i++){
        for(int j=1;j<=M;j++){
            dp[i][j][0]=max(dp[i-1][j][0], max(dp[i-1][j][1], dp[i-1][j][2]))+d[i][j];
        }
        for(int j=1;j<=M;j++){
            dp[i][j][1]=max(dp[i][j-1][0], dp[i][j-1][1])+d[i][j];
        }
        for(int j=M-1;j>0;j--){
            dp[i][j][2]=max(dp[i][j+1][0], dp[i][j+1][2])+d[i][j];
        }
    }
    printf("%d ",max(dp[N][M][0], max(dp[N][M][1], dp[N][M][2])));
    return 0;
}
