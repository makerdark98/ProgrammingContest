#include <iostream>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
lld gcd(lld a, lld b){
    lld t = a%b;
    while(t!=0){
        a = b;
        b = t;
        t = a%b;
    }
    return b;
}
lld lcm(lld a, lld b){
    return a /gcd(a, b) * b;
}
int main() {
    int T;
    sci(T);
    while (T--) {
        lld a, b;
        scl(a), scl(b);
        printf("%lld\n", lcm(a, b));
    }
    return 0;
}
