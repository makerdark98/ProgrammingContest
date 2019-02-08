#include <iostream>
#include <vector>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
int main() {
    lld r, k, im;
    scl(r), scl(k), scl(im);
    lld ans=0;
    while(k!=im){
        ans++;
        k=(k+1)/2;
        im=(im+1)/2;
    }
    printf("%lld", ans);
    return 0;
}
