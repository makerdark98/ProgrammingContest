//
// Created by lmu on 18. 9. 26.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%d", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%d ", (n))
#define MOD 10e9L+7
using namespace std;
typedef int lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
lld L, N, M;

vi a, b;
int main(){
    scl(L), scl(N);
    a.resize(N);
    for(int i=0;i<N;i++) scl(a[i]);
    scl(M);
    b.resize(M);
    for(int i=0;i<M;i++) scl(b[i]);
    lld size = min(N, M);
    lld result=0;
    for(int i=0;i<size;i++){
        if(a[i]!=b[i]) result++;
    }
    prl(result);
    return 0;
}
