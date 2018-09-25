//
// Created by lmu on 18. 9. 25.
//
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld", (n))
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;
typedef vector<lld> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

lld next(lld N){
    lld result = 0;
    while(N>0){
        result+=(N%10)*(N%10);
        N/=10;
    }
    return result;
}
int main(){
    vector<bool> visited(1000000000, false);
    lld N;
    scl(N);
    visited[N]=true;
    while(N!=1){
        N = next(N);
        if(visited[N]){
            printf("UNHAPPY");
            return 0;
        }
        visited[N]=true;
    }
    printf("HAPPY");
    return 0;
}