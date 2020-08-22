#include <iostream>
#include <vector>
#include <algorithm>
#define sci(N) scanf("%d", &(N))
#define MAX_V 100010
using namespace std;
vector<int> edges[MAX_V];
vector<int> reverse_edges[MAX_V];
pair<int, int> data[MAX_V];
int in[MAX_V], out[MAX_V];
int order[MAX_V];
int scc_n[MAX_V];
int cnt;
int T, N, M, a, b;

void dfs(int idx) {
  in[idx] = ++ cnt;

  for (const int& to : edges[idx]) {
    if (in[to] == 0) {
      dfs(to);
    }
  }
  out[idx] = ++cnt;
}

void scc(int idx) {
  for (const int& to : reverse_edges[idx]) {
    if (scc_n[to] == 0) {
      scc_n[to] = scc_n[idx];
      scc(to);
    }
  }
}

int main () {
  sci(T);
  while (T --) {
    sci(N), sci(M);
    cnt = 0;
    for (int i = 1; i <= N; i ++) {
      scc_n[i] = in[i] = out[i] = 0;
      edges[i].resize(0);
      reverse_edges[i].resize(0);
      order[i] = i;
    }
    for (int i = 0; i < M; i ++) {
      sci(data[i].first), sci(data[i].second);
      edges[data[i].first].push_back(data[i].second);
      reverse_edges[data[i].second].push_back(data[i].first);
    }

    for (int i = 1; i <= N; i ++) 
      if (in[i] == 0) dfs(i);


    sort(order + 1, order + 1 + N, [](const int& a, const int& b) -> bool {
        return out[a] > out[b];
        });
    int result = 0;
    int cnt = 0;

    for (int i = 1; i <= N; i ++) {
      if (scc_n[order[i]] == 0) {
        scc_n[order[i]] = ++ cnt;
        scc(order[i]);
      }
    }
    vector<int> indegree(cnt + 1, 0);
    for (int i = 0; i < M; i ++) {
      if (scc_n[data[i].first] != scc_n[data[i].second]) indegree[scc_n[data[i].second]] ++;
    }
    for (int i = 1; i <= cnt; i ++) if (indegree[i] == 0) result ++;

    printf("%d\n", result);
  }
  return 0;
}
