#include <stdio.h>
#include <stdlib.h>

int A[100001];
int N;
int compare(void *first, void* second){
    if(*(int*)first> *(int*)second){
        return 1;
    }
    else if(*(int*)first<*(int*)second){
        return -1;
    }
    return 0;
}

int B_S(int s, int e, int search){
    int m = (s+e)/2;
    if(s>e) return 0;
    if(A[m]==search) return 1;
    else if(A[m]>search) return B_S(s,m-1,search);
    else return B_S(m+1, e, search);
}

int main() {
    int i, j, min_idx, tmp, T, search;
    scanf("%d", &N);
    for(i=0;i<N;i++) {
        scanf("%d",&A[i]);
    }
    qsort(A, N, sizeof(int), compare);
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d", &search);
        printf("%d\n", B_S(0, N-1, search));
    }
    return 0;
}