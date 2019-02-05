#include <iostream>

int main() {
    int T;
    scanf("%d",&T);
    for(int i =1;i<=T;i++){
        int L, W, H;
        scanf("%d %d %d",&L,&W,&H);
        printf("Case %d: ",i);
        if(L<=20 && W<=20 && H <=20){
            printf("good\n");
        }
        else
            printf("bad\n");
    }
    return 0;
}