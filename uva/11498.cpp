#include <iostream>

int main() {
    int K;
    int N, M, X, Y;
    while(true) {
        scanf("%d", &K);
        if (!K) return 0;
        scanf("%d %d", &N, &M);
        while (K--) {
            int n, e;
            scanf("%d %d", &X, &Y);
            if (Y > M) {
                n = 1;
            } else if (Y < M) {
                n = 0;
            } else {
                n = -1;
            }
            if (X > N) {
                e = 1;
            } else if (X < N) {
                e = 0;
            } else {
                e = -1;
            }
            if (n == -1 || e == -1) {
                printf("divisa");
            } else {
                if (n == 1) printf("N");
                else printf("S");
                if (e == 1) printf("E");
                else printf("O");
            }
            printf("\n");
        }
    }
    return 0;
}