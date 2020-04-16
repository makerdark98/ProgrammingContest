#include <iostream>
#include <vector>
#define sci(n) scanf("%d",&(n))
#define scl(n) scanf("%I64d",&(n))
using namespace std;
using lld = long long;
using vi = vector<lld>;

lld H, n;
vi d;
lld solve();
int main(){
    scl(H), scl(n);
    d.resize(n);
    for(lld i=0;i<n;i++){
        scl(d[i]);
    }
    printf("%I64d", solve());
    return 0;
}
lld solve() {
    lld minSum=0, sum=0, result = 0;
    for(lld i=0;i<n;i++){
        sum+=d[i];
        minSum = minSum < sum ? minSum : sum;
    }
    if(sum>=0 || H <= -minSum) {
        lld now = H;
        for(lld i=0;i<n;i++){
            now += d[i];
            result ++;
            if(now<=0) return result;
        }
        return -1;
    }
    lld cycle = (H+minSum) / sum;
    result += -cycle * n;
    lld now = H - sum*cycle;
    for(lld i=0;;i++){
        now += d[i%n];
        result ++;
        if(now<=0) return result;
    }
    return 0;
}
