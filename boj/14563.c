#include <stdio.h>

int main() {
    int T, N;
    int i, sum, j;
    scanf("%d", &T);

    for(i=0;i<T;i++){
        scanf("%d", &N);
        sum = 0;
        for(j=1;j<N;j++){
            if(N%j==0) {
                sum += j;
            }
        }
        if(sum==N) printf("Perfect\n");
        else if(sum<N) printf("Deficient\n");
        else printf("Abundant\n");
    }
    return 0;
}