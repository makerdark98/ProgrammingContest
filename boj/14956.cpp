//
// Created by lmu on 18. 9. 25.
//


#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d ", (n))
#define prl(n) printf("%lld ", (n))
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

lld N, M;
pii search(lld n, lld m){
    if(n==2){
        switch(m){
            case 1: return {1,1};
            case 2: return {1,2};
            case 3: return {2,2};
            case 4: case 0: return {2,1};
        }
    }
    lld q = n/2;
    auto result=search(n/2, m%(q*q));
    lld r = ceil((double)m/(q*q));
    switch(r){
        case 1: swap(result.first, result.second); return result;
        case 2: result.second += q; return result;
        case 3: result.first += q; result.second +=q; return result;
        case 4: case 0:
            result.first *= -1;
            result.second *= -1;
            result.first += q+1;
            result.second += 2*q+1;
            swap(result.first, result.second);
            return result;
    }
}
int main(){
    scl(N), scl(M);
    auto result = search(N, M);
    prl(result.first), prl(result.second);

    return 0;
}