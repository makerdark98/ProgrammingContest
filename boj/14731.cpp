#include <iostream>
using namespace std;

#define MOD 1000000007
long long fastpow(long long base, long long power){
    long long ans=1;
    while(power>0){
        if(power%2==1){
            ans = (ans*base) %MOD;
        }
        base=(base*base) %MOD;
        power/=2;
    }
    return ans;
}
int main(){
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long c, k;
        scanf("%lld %lld",&c,&k);
        sum+= (c*((k%MOD)*fastpow(2, k-1)%MOD)%MOD);
        sum%= MOD;
    }
    printf("%lld\n", sum);
    return 0;
}
