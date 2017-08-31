#include <stdio.h>
#include <vector>
#define MAX 10000
using namespace std;
int main(){
    vector<int> num;
    num.assign(MAX,true);
    for(int i=2;i<MAX;i++){
        if(num[i]){
            for(int j=2;i*j<MAX;j++){
                num[i*j]=false;
            }
        }
    }
    int T,n;
    scanf("%d",&T);
    while(T--){
        int a=2;
        scanf("%d",&n);
        for(int i=2;i<=n/2;i++){
            if(num[i]&&num[n-i]) a=i;
        }
        printf("%d %d\n", a, n-a);
    }
    return 0;
}
