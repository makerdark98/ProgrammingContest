#include <iostream>
#include <algorithm>
#define sci(n) scanf("%lld", &(n))
typedef long long lld;
using namespace std;
lld K, N;
lld x[10010];
int chk(int l){
    lld cnt=0;
    for(lld i=0;i<K;i++){
        cnt+=x[i]/l;
    }
    if(cnt>=N) return 1;
    return 0;
}
int main(){
    sci(K), sci(N);
    for(lld i=0;i<K;i++) sci(x[i]);
    sort(x,x+K);
    lld s=0, e=x[K-1];
    while(s+1<e){
        lld m=(s+e)/2;
        if(chk(m)) s=m;
        else e=m;
    }
    if(chk(e)) s=e;
    printf("%lld\n",s);
    return 0;
}
