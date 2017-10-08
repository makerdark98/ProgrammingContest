#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n+1);
    vector<int> dp[2];
    dp[0].assign(n+1,0);
    dp[1].assign(n+1,0);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[1][1]=a[1];
    dp[0][2]=a[2];
    dp[1][2]=a[1]+a[2];
    for(int i=3;i<=n;i++){
        dp[0][i] = max(dp[0][i-2], dp[1][i-2])+a[i];
        dp[1][i] = dp[0][i-1]+a[i];
    }
    printf("%d\n", max(dp[0][n], dp[1][n]));
    return 0;
}
