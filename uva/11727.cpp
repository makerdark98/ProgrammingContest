#include <iostream>
#define min(x,y) (x>y?y:x)
int main() {
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        printf("Case %d: %d\n",i,min(a,b)^min(b,c)^min(c,a));
    }
    return 0;
}