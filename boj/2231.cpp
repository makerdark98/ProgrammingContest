#include <iostream>
using namespace std;
typedef long long lld;
#define MAX 10e12
#define sci(n) scanf("%lld", &(n))
lld N;
int main(){
    sci(N);
    lld result =MAX;
    for(lld i=N-1;i>=0;i--){
        lld s=i, t=i;
        while(t>0){
            s+=t%10;
            t/=10;
        }
        if(s==N && result>i) result=i;
    }
    if(result==MAX) result=0;
    printf("%lld\n",result);
    return 0;
}
