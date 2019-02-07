#include <iostream>
#include <vector>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
using vi = vector<lld>;
lld gcd(lld a, lld b){
    lld t = a%b;
    while(t!=0) { a = b; b = t; t = a%b; }
    return b;
}
int main(){
    int N;
    sci(N);
    vi input(N);
    for(lld i=0;i<N;i++)
        scl(input[i]);
    lld g = input[0];
    for(lld i=1;i<N;i++) {
        g = gcd(input[0], input[i]);
        printf("%lld/%lld\n",input[0]/g, input[i]/g);
    }
    return 0;
}
