#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
typedef long long lld;
lld fastpow(lld x, lld y){
    lld result = 1;
    while(y>0){
        if(y%2){
            result *= x;
            result %= MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return result;
}

lld fac[4000001], n, k, facinv[4000001];
int main(){
    fac[1] = 1;
    for(int i=2;i<=4000000;i++) fac[i]=(fac[i-1]*i)%MOD;
    facinv[4000000] = fastpow(fac[4000000], MOD-2);
    for(int i=4000000-1;i>=0;i--) facinv[i]=(facinv[i+1]*(i+1))%MOD;
    scanf("%lld %lld",&n,&k);
    if(n==k|| !k){
        printf("1");
        return 0;
    }
    lld ans=(fac[n]*facinv[n-k])%MOD;
    ans = (ans*facinv[k])%MOD;
    printf("%lld", ans);
    return 0;
}
