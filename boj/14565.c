#include <stdio.h>
long long extended_gcd(long long, long long);

int main() {
    long long int N, A;
    scanf("%lld %lld", &N, &A);
    printf("%lld ", N>A?N-A:A-N);
    printf("%lld ", extended_gcd(N,A));
    return 0;
}
long long extended_gcd(long long A, long long B){
    long long r, q, inverse =1;
    while(B!=0){
        r = A%B;
        q = A/B;
        printf("%d ",q);
        inverse*=q;
        inverse++;
        A = B;
        B = r;
    }
    if(A!=1) return -1;
    return inverse;
}