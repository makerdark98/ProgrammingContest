#include <stdio.h>

int T[505][505];
int D[505][505];
int main(){
    int i, j, n, max;
    scanf("%d", &n);
    for( i = 0 ; i < n ; i++){
        for( j = 0 ; j <= i ; j++){
            scanf("%d", &T[i][j]);
        }
    }
    D[0][0] = T[0][0];
    for( i = 1 ; i < n ; i++){
        for ( j = 0 ; j <= i; j++){
            if(j==0) D[i][j] = D[i-1][j] + T[i][j];
            else if(j==i) D[i][j] = D[i-1][j-1] + T[i][j];
            else D[i][j] = (D[i-1][j-1] > D[i-1][j]) ? D[i-1][j-1] + T[i][j] : D[i-1][j] + T[i][j];
        }
    }
    max = 0;
    for( i = 0 ; i < n ; i++){
        if(max<D[n-1][i]) max = D[n-1][i];
    }
    printf("%d", max);
    return 0;
}