#include <stdio.h>
#include <vector>
#define MAX 300000
using namespace std;

int main(){
    int n;
    vector<bool> num;
    num.assign(MAX, true);
    for(int i=2;i<MAX;i++){
        if(num[i]){
            for(int j=2;i*j<MAX;j++){
                num[i*j]=false;
            }
        }
    }
    num[1]=false;
    while(scanf("%d", &n)){
        int count=0;
        if(n==0){
            break;
        }
        for(int i=n+1;i<=2*n;i++){
            if(num[i]){
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
