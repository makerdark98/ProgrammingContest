#include <iostream>
#define sci(n) scanf("%lld", &(n))
typedef long long lld;
using namespace std;
lld N, ans;
int chk(lld a){
    while(a>0){
        if(a%10!=4 && a%10 != 7) return 0;
        a/=10;
    }
    return 1;
}
int main(){
    sci(N);
    for(lld i=4;i<=N;i++){
        if(chk(i)) ans=i;
    }
    printf("%lld\n",ans);
    return 0;
}
