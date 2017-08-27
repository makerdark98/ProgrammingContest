#include <stdio.h>

int main() {
    int N,M,A, input;
    scanf("%d %d %d", &N, &M, &A);
    A--;
    while(scanf("%d",&input), input!=M/2+1) {
        A -= M / 2 + 1;
        while (A < 0) {
            A += N;
        }
        A += input;
        if (A + 1 >= N) {
            A = A % N;
        }
        printf("%d\n", A + 1);
    }
    printf("0\n");
    return 0;
}