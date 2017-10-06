#include <iostream>
using namespace std;
long long fac[13];

int main(){
    int n;
    scanf("%d",&n);
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i;
    }
    printf("%lld\n",fac[n]);
    return 0;
}
