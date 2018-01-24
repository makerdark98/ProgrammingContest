#include <iostream>
#define sci(n) scanf("%lld",&(n))
typedef long long lld;
using namespace std;

lld N, M, K;
lld dp[310][310], m[310][310];
int main(){
    sci(N),sci(M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            sci(m[i][j]);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + m[i][j];
        }
    }
    sci(K);
    for(int i=0;i<K;i++){
        lld sr,er,sc,ec;
        sci(sr),sci(sc),sci(er),sci(ec);
        printf("%lld\n", dp[er][ec]-dp[sr-1][ec]-dp[er][sc-1]+dp[sr-1][sc-1]);
    }
    return 0;
}
