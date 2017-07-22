#include <stdio.h>

int main() {
    int a, b, i;
    scanf("%d %d", &a, &b);
    for(i=1;;i++){
        a-=i;
        if(a<0){
            printf("Vladik\n");
            return 0;
        }
        i++;
        b-=i;
        if(b<0){
            printf("Valera\n");
            return 0;
        }
    }
    return 0;
}