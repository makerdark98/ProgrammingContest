#include <iostream>
#include <vector>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
int main() {
    lld X;
    scl(X);
    lld ans=0;
    while(X>0) {
        ans += X%2;
        X /= 2;
    }
    printf("%lld", ans);
    return 0;
}
