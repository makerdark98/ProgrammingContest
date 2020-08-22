#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int N, M;
int m[1010][1010];
int dp[1010][1010][2];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int main () {
  scanf("%d%d", &N, &M);

  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= M; j ++) {
      scanf("%1d", &m[i][j]);
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
    }
  }

  queue<pair<int, int>> q;
  dp[1][1][0] = 1;

  q.push({1, 1});
  while (!q.empty()) {
    pair<int, int> f = q.front(); q.pop();
    int& r = f.first;
    int& c = f.second;
    if (r == N && c == M) break;
    if (r <= 0 || c <= 0 || r > N || c > M) continue;
    for (int i = 0; i < 4; i ++) {
      bool chk = false;
      if (m[r + dr[i]][c + dc[i]] == 0) {
        if (dp[r + dr[i]][c + dc[i]][0] > dp[r][c][0] + 1) {
          dp[r + dr[i]][c + dc[i]][0] = dp[r][c][0] + 1;
          chk = true;
        }

        if (dp[r + dr[i]][c + dc[i]][1] > dp[r][c][1] + 1) {
          dp[r + dr[i]][c + dc[i]][1] = dp[r][c][1] + 1;
          chk = true;
        }
      } else {
        if (dp[r + dr[i]][c + dc[i]][1] > dp[r][c][0] + 1) {
          dp[r + dr[i]][c + dc[i]][1] = dp[r][c][0] + 1;
          chk = true;
        }
      }
      if (chk) q.push({r + dr[i], c + dc[i]});
    }
  }

  int retval = min (dp[N][M][0], dp[N][M][1]);
  printf("%d", retval == INF ? -1: retval);

  return 0;
}
