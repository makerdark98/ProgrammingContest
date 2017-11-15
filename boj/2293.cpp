#include <iostream>
#define sci(n) scanf("%d",&(n))
using namespace std;
int main(){
    int n,k, coin[101], money[10001]={0};
    sci(n), sci(k);
    for(int i=0;i<n;i++){
        sci(coin[i]);
    }
    money[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j>=coin[i]) money[j] += money[j-coin[i]];
        }
    }
    printf("%d",money[k]);
    return 0;
}
