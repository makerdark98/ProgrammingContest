#include <iostream>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    long long fibo[200];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<=41;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    while(T--){
        int n;
        scanf("%d",&n);
        if(n==0) printf("1 0\n");
        else if(n==1) printf("0 1\n");
        else printf("%lld %lld\n", fibo[n-1], fibo[n]);
    }
    return 0;
}
