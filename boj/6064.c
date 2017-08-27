#include <stdio.h>


int main() {
    int T, M, N, x, y;
    int i, tmp, k;
    scanf("%d", &T);
    for(i=0 ; i<T ; i++){
        k=-1;
        scanf("%d %d %d %d", &M, &N, &x, &y);
        for(tmp=0;tmp<=N;tmp++){
            if(N==y&&(M*tmp+x)%N==0){
                k=M*tmp+x;
                break;
            }
            if((M*tmp+x)%N == y){
                k=M*tmp+x;
                break;
            }
        }
        printf("%d\n", k);

    }
    return 0;
}