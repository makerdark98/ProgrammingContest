#include <iostream>
#include <vector>
using namespace std;
using lld = long long;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
vector<lld> dp;
lld solve(int n){
    if(dp.size()-1 < (size_t)n || dp[n] == 0) {
        dp.resize(n+1, 0);
        dp[n] = solve(n-2) + solve(n-3);
    }
    return dp[n];
}
int main() {
    int T;
    sci(T);
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(1);
    while(T--){
        int N;
        sci(N);
        printf("%lld\n", solve(N));
    }
    return 0;
}
