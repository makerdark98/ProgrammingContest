#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
int main () {
    lld N, L;
    scl(N), scl(L);
    while((N-(L*(L-1)/2))%L != 0 && L <= 100) L++;
    if(L>100 || (N-(L*(L-1)/2)) < 0) {
        printf("-1");
        return 0;
    }
    else {
        for(lld i=0;i<L;i++) {
            printf("%lld ", (N-(L*(L-1)/2))/L + i);
        }
    }
    return 0;
}
