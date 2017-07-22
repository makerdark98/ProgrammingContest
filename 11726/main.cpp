#include <stdio.h>
int F[1100];

int f(int n){
    if(F[n]!=0) return F[n];
    F[n]=f(n-1)%10007 + f(n-2)%10007;
    return F[n];
}
int main(){
    int n;
    F[0]=1;
    F[1]=1;
    scanf("%d", &n);
    printf("%d", f(n)%10007);
    return 0;
}