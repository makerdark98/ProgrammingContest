#include <iostream>
#include <vector>
#include <queue>
#define sci(n) scanf("%d", &(n))

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main () {
  int N;
  sci(N);
  vi nodes(N+1, 0);
  vi visited(N+1, 0);
  vi indegree(N+1, 0);
  vvi edges(N+1);
  for(int i=1;i<N;i++){
    int a,b;
    sci(a), sci(b);
    edges[a].push_back(b);
    edges[b].push_back(a);
    indegree[a] ++;
    indegree[b] ++;
  }
  queue<int> q;
  int result = 0;
  visited[1] = 1;
  nodes[1] = 0;
  q.push(1);
  while(!q.empty()) {
    int f = q.front(); q.pop();
    for(int i=0;i<edges[f].size();i++){
      if(!visited[edges[f][i]]) {
        visited[edges[f][i]] = 1;
        nodes[edges[f][i]] = nodes[f] + 1;
        q.push({edges[f][i]});
      }
    }
  }
  for(int i=2;i<=N;i++){
    if(indegree[i] == 1) result += nodes[i];
  }

  printf("%s", result % 2 == 1 ? "YES" : "NO");

  return 0;
}
