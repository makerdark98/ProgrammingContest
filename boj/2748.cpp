#include <iostream>
using namespace std;

long long fibo[200];

int main(){
    int n;
    scanf("%d",&n);
    fibo[1]=0;
    fibo[2]=1;
    for(int i=3;i<=n+1;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    printf("%lld\n",fibo[n+1]);
    return 0;
}

