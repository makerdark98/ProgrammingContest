#include <iostream>
typedef long long ll;
ll gcd(ll a, ll b){
    ll tmp;
    while(b){
        tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", (a/gcd(a,b))*b);
    }
    return 0;
}
