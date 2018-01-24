#include <iostream>
using namespace std;
typedef long long lld;
#define sci(n) scanf("%lld", &(n))

lld divide(lld n, lld r, lld c){
    if(n==0) return 0;
    lld n1 = n-1;
    lld Num = 1<<n1;
    if(r/Num==0 && c/Num == 0) return divide(n1, r%Num, c%Num);
    else if(r/Num == 0 && c/Num == 1) return divide(n1, r%Num, c%Num) + Num*Num;
    else if(r/Num == 1 && c/Num== 0) return divide(n1, r%Num, c%Num) + Num*Num*2;
    else return divide(n1,r%Num, c%Num) + Num*Num*3;
}

int main(){
    lld N, r, c;
    sci(N), sci(r), sci(c);
    printf("%lld\n",divide(N,r,c));
    return 0;
}
