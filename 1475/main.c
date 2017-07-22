#include <stdio.h>
#include <math.h>

int main() {
    int N,max=0,i;
    scanf("%d", &N);
    int number[10]={0};
    while(N>9){
        number[N%10]++;
        N/=10;
    }
    number[N]++;
    number[6]=(int)ceil((number[6]+number[9])/2);
    for(i=0;i<9;i++){
        if(max<number[i]) max=number[i];
    }
    printf("%d",max);
    return 0;
}