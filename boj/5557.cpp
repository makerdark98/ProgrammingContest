#include <iostream>
using namespace std;
#define sci(n) scanf("%d",&(n))
int N;
int A[101];
long long dp[101][21];
int main(){
    sci(N);
    for(int i=0;i<N;i++) sci(A[i]);
    dp[0][A[0]]=1;
    for(int i=1;i<N-1;i++){
        for(int j=0;j<21;j++){
            if(j+A[i]<21) dp[i][A[i]+j]+=dp[i-1][j];
            if(j-A[i]>=0) dp[i][j-A[i]]+=dp[i-1][j];
        }
    }
    printf("%lld\n",dp[N-2][A[N-1]]);
    return 0;
}
