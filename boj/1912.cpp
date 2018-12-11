#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef vector<lld> vi;
int main(){
    int n;
    scanf("%d",&n);
    vi dp;
    dp.assign(n+1, 0);   // 안더한거
    vi a(n+1, 0);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        dp[i] = max(a[i], dp[i-1]+a[i]);
    }
    lld ans=dp[1];
    for(int i=1;i<=n;i++){
        ans=max(ans, dp[i]);
    }
    printf("%lld", ans);
    return 0;
}
