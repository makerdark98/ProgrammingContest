#include<iostream>
#include<cmath>
using namespace std;
#define sci(n) scanf("%d",&(n));
int dp[10001],s[10001];
int main(){
    int n;
    sci(n);
    for(int i=1;i<=n;i++){
        sci(s[i]);
    }
    dp[1]=s[1];
    dp[2]=s[1]+s[2];
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-3]+s[i]+s[i-1],max(dp[i-2]+s[i],dp[i-1]));
    }
    printf("%d",dp[n]);
    return 0;
}
