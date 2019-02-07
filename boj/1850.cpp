#include <iostream>
using namespace std;
using lld = long long;
#define scl(n) scanf("%lld", &(n))
lld gcd(lld a, lld b){
    lld t= a%b;
    while(t!=0){
        a=b;
        b=t;
        t=a%b;
    }
    return b;
}

int main() {
    lld a, b;
    scl(a), scl(b);
    lld g = gcd(a,b);
    for(lld i=0;i<g;i++){
        printf("1");
    }
    return 0;
}
