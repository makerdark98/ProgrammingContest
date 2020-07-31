#include <iostream>
#include <vector>
#include <algorithm>
#define sci(N) scanf("%d", &(N))
#define MOD 15746
using namespace std;
int N;

int dp[1000010];
int main () {
    sci(N);
    dp[0] = 1;
    for (int i = 0; i < N; i ++) {
        dp[i] %= MOD;
        dp[i+1] += dp[i] % MOD;
        dp[i+2] += dp[i] % MOD;
    }
    printf("%d", dp[N] % MOD);
    return 0;
}
