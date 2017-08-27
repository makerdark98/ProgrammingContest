#include <stdio.h>

int main(){
    long long A, imsiA, tmp;
    int T, i, n, output;

    scanf("%d", &T);

    for(i=0;i<T;i++){
        scanf("%lld %d", &A, &n);
        tmp = 1;
        while(tmp<A){
            tmp *= n;
        }
        output = 1;
        tmp /= n;
        imsiA= A;
        while(tmp!=1){
            if(A/tmp%n!=imsiA%n) output = 0;
            tmp /= n;
            imsiA /= n;
        }
        printf("%d\n", output);
    }
    return 0;
}