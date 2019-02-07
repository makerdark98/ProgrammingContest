#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lld = long long;
using vi = vector<lld>;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
lld gcd(lld a, lld b){
    lld t=a%b;
    while(t!=0) { a=b; b=t; t=a%b; }
    return b;
}
int main() {
    int N;
    lld res;
    sci(N);
    vi input(N);
    for(lld i=0;i<N;i++) scl(input[i]);
    res = abs(input[0]-input[1]);
    for(lld i=2;i<N;i++) res = gcd(res, abs(input[0]-input[i]));
    vi output;
    for(lld i=1;i*i<=res;i++) {
        if(res%i==0) {
            output.push_back(i);
            if(res/i!=i) output.push_back(res/i);
        }
    }
    sort(output.begin(), output.end());
    for(size_t i=1;i<output.size();i++){
        printf("%lld ",output[i]);
    }
    return 0;
}
