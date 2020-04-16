#include <iostream>
#include <vector>
using namespace std;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%I64d", &(n))
#define pri(n) printf("%d", (n))
#define prl(n) printf("%I64d", (n))
using lld = long long;
using vi = vector<lld>;
lld solve(lld n, lld m);
int main(){
    lld n, m;
    scl(n), scl(m);
    prl(solve(n, m));
    return 0;
}
lld solve(lld n, lld m){
    if(m%n != 0) return -1;
    lld result = 0;
    lld q= m/n;
    while(q!=1) {
        if(q%2 == 0) {
            q /=2;
            result ++;
        }
        else if(q%3 == 0) {
            q /=3;
            result ++;
        } else {
            return -1;
        }
    }
    return result;
}
