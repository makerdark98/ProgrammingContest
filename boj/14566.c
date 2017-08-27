#include <stdio.h>
#include <stdlib.h>


int main() {
    int N, i, j, max, tmp, dis, pair;
    int* A;
    scanf("%d", &N);
    A=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    for(i=0;i<N;i++){
        max=i;
        for(j=i;j<N;j++){
            if(A[max]<A[j]) max = j;
        }
        tmp=A[max];
        A[max]=A[i];
        A[i]= tmp;
    }
    dis = 99999999;
    pair = 1;
    for(i=0;i<N-1;i++){
        if(dis>A[i]-A[i+1]){
            dis=A[i]-A[i+1];
            pair=1;
        }
        else if(dis==A[i]-A[i+1]){
            pair++;
        }
    }
    printf("%d %d", dis, pair);



    free(A);
    return 0;
}