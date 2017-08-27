#include <stdio.h>

int main(){
    int T, H, W, N;
    int i;
    scanf("%d", &T);
    for(i = 0; i < T; i++){
        scanf("%d %d %d", &H, &W, &N);
        if(N%H==0) {
            N = H*100 + N/H;
        }
        else N = N%H*100 + N/H+1;
        printf("%d\n", N);
    }
    return 0;
}