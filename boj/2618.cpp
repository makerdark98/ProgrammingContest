#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define sci(N) scanf("%d", &(N))
#define scl(N) scanf("%lld", &(N))
using lld = long long;


pair<int, int> data[1010];
int result_map[1010];
lld dp[1010][1010];
pair<int, int> parent[1010][1010];
int N, W;

lld dist(int a, int b){
    return abs(data[a].first - data[b].first) + abs(data[a].second - data[b].second);
}

int main () {
    sci(N), sci(W);
    data[0] = {1, 1};
    data[1] = {N, N};
    for (int i=2;i<W+2; i++){
        sci(data[i].first), sci(data[i].second);
    }
    
    for (int i=0;i<W+2;i++) {
        for (int j=0;j<W+2;j++) {
            dp[i][j] = N * N * W;
        }
    }
    dp[0][1] = 0;
    
    for (int i=0;i<W+1;i++) {
        for (int j=0;j<W+1;j++) {
            if (i==j) continue;
            
            if (dp[i][j] + dist(i, max(i, j) + 1) < dp[max(i, j) + 1][j]) {
                dp[max(i, j) + 1][j] = dp[i][j] + dist(i, max(i, j) + 1);
                parent[max(i, j) + 1][j] = {i, j};
            }
            
            if (dp[i][j] + dist(max(i, j) + 1, j) < dp[i][max(i,j) + 1]) {
                dp[i][max(i, j) + 1] = dp[i][j] + dist(max(i, j) + 1, j);
                parent[i][max(i, j) + 1] = {i, j};
            }
        }
    }
    
    lld result = N * N * W;
    pair<int, int> result_start;
    for (int i=0;i<W+1; i++) {
        if (result > dp[W+1][i]) {
            result = dp[W+1][i];
            result_start = {W + 1, i};
        }
        
        if (result > dp[i][W+1]) {
            result = dp[i][W+1];
            result_start = {i, W + 1};
        }
    }
    
    while (!(result_start.first == 0 && result_start.second == 0)) {
        result_map[result_start.first] = 1;
        result_map[result_start.second] = 2;
        result_start = parent[result_start.first][result_start.second];
    }
    
    printf("%lld\n", result);
    for(int i=2;i<W+2;i++) {
        printf("%d\n", result_map[i]);
    }
    
    return 0;
}
