#include <iostream>
#include <cmath>
#define scl(n) scanf("%I64d", &(n))
using namespace std;
using lld = long long;
int main () {
    lld n;
    scl(n);
    if(n%2==1) {
        printf("0");
    } else {
        printf("%I64d", 1LL << (n/2));
    }
    return 0;
}
