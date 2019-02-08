#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
int main() {
    lld a, b;
    lld r = 0;
    lld ans = 0;
    for(lld i=0;i<4;i++){
        scl(a), scl(b);
        r-=a;
        r+=b;
        ans = max(ans, r);
    }
    printf("%lld", ans);
    return 0;
}
