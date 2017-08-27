#include <stdio.h>
int A[1001][1001];
int D[1001];
int N,M;
int main(){
    int i, max ,j, k;
    scanf("%d %d", &N, &M);
    for(i=0;i<M;i++){
        scanf("%d %d", &j, &k);
        A[j][k]++;
    }
    for(i=1;i<=N;i++){
        max = 0;
        for(j=1;j<i;j++){
            if(A[j][i]){
                if(max<D[j]) max=D[j];
            }
        }
        D[i]+=(max+1);
    }
    for(i=1;i<=N;i++){
        printf("%d ",D[i]);
    }
}
