#include <stdio.h>

int main() {
    int T, k, n;
    int i, j, l;
    int Combination[50][50]={0};
    scanf("%d", &T);
    Combination[1][1] = 1;
    for( i = 0; i < T; i++){
        scanf("%d %d", &k, &n);
        k++;
        for( j = 2 ;  j<=(n+k) ; j++){
            for( l = 1; l <= (k+1) ; l++){
                if(Combination[j][l]==0){
                    Combination[j][l] = Combination[j-1][l-1] + Combination[j-1][l];
                }
            }
        }
        printf("%d\n", Combination[n+k][k+1]);
    }
    return 0;
}