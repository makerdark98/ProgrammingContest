#include <stdio.h>
#include <stdlib.h>
int main(){
    int sum=0;
    int input;
    int tmp = 1;
    while(scanf("%d",&input)!=EOF){
        if(input<0) tmp = -1;
        sum+=abs(input)*tmp;
    }
    printf("%d\n",sum);
    return 0;
}