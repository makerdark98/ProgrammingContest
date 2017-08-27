#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n, k, i;
    scanf("%d", &k);
    n = ceil(((float)-1+sqrt(1+8*k))/2);
    i = abs(k-(n*(n+1)/2))+1;
    if(n%2 == 0){
        printf("%d/%d", n-i+1, i);
    }
    else{
        printf("%d/%d", i, n-i+1);
    }
    return 0;
}