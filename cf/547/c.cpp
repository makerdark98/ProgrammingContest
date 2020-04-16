#include <iostream>
#include <vector>
using namespace std;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%I64d", &(n))
using lld = long long;
using vi = vector<lld>;
lld solve();
int n;
lld minData = 0;
vi p, chk;
int main() {
    sci(n);
    p.assign(n, 0);
    chk.assign(n+1, 0);
    for(int i=1;i<n;i++){
        lld tmp;
        scl(tmp);
        p[i] = p[i-1] + tmp;
        minData = minData < p[i] ? minData : p[i];
    }
    if(solve() == -1) {
        printf("-1");
    }else {
        for(int i=0;i<n;i++){
            printf("%I64d ",p[i]);
        }
    }
    return 0;
}
lld solve(){
    for(int i=0;i<n;i++){
        p[i]+=(-1)*minData+1;
        if(p[i] > n) return -1;
        chk[p[i]] = 1;
    }
    for(int i=1;i<=n;i++){
        if(!chk[i]) return -1;
    }
    return 1;
}
