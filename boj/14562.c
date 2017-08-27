#include <stdio.h>

int kick(int S, int T);
int main() {
    int C, S, T;
    int i;
    scanf("%d", &C);
    for(i=0;i<C;i++){
        scanf("%d %d", &S, &T);
        printf("%d\n", kick(S,T));

    }
    return 0;
}

int kick(int S, int T){
    int A, B;
    if(S==T) return 0;
    else if(S>T) return 9999999;
    A = kick(S*2, T+3);
    B = kick(S+1, T);
    return (A<B?A:B) +1;
}
