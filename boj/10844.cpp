#include<iostream>
#include<vector>
using namespace std;
typedef long long lld;
#define sci(n) scanf("%lld", &(n));
#define MOD 1000000000L
int main(){
    lld n;
    sci(n);
    lld dp[10][2]={0,};
    for(int i=1;i<10;i++) dp[i][0]=1;
    int chk=0;
    for(int i=1;i<n;chk=!chk,i++){
        dp[0][!chk]=0;
        for(int i=1;i<10;i++){
            dp[i][!chk]=dp[i-1][chk];
            dp[i][!chk]%=MOD;
        }
        for(int i=8;i>=0;i--){
            dp[i][!chk]+=dp[i+1][chk];
            dp[i][!chk]%=MOD;
        }
    }
    lld result=0;
    for(int i=0;i<10;i++){
        result+=dp[i][chk]%MOD;
        result=result%MOD;
    }
    printf("%lld\n",result);
    return 0;
}
