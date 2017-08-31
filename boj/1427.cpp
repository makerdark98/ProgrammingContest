#include <stdio.h>
int main(){
    char c;
    long long n[10]={0};
    while(scanf("%c",&c)!=EOF){
        n[c-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<n[i];j++){
            printf("%d",i);
        }
    }
    return 0;
}
