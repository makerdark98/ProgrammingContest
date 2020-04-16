#include <iostream>
#include <vector>
using namespace std;
#define scl(n) scanf("%I64d", &(n))
#define sci(n) scanf("%d", &(n))
using lld = long long;
using vi = vector<lld>;

int main(){
    int n;
    sci(n);
    vi data(n, 0);
    for(int i=0;i<n;i++){
        scl(data[i]);
    }
    lld result=0, tmp=0;
    for(int i=0;i<2*n;i++){
        if(data[i%n]) {
            tmp ++;
            result = result > tmp ? result : tmp;
        } else {
            tmp = 0;
        }
    }
    printf("%I64d", result);
    return 0;
}
