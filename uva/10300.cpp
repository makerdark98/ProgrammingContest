#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
#define scl(n) scanf("%lld", &(n))
#define sci(n) scanf("%d", &(n))
int main(){
    int T;
    sci(T);
    while(T--){
        int f;
        sci(f);
        lld result = 0;
        for(int i=0;i<f;i++){
            int a, b, c;
            sci(a), sci(b), sci(c);
            result += a*c;
        }
        printf("%lld\n", result);
    }
    return 0;
}
