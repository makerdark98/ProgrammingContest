#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define sci(n) scanf("%d", &(n))
#define MAX_SIZE 100010
#define MAX_NUMBER 1000010

int web[MAX_NUMBER];
int data[MAX_SIZE];
int data_check[MAX_NUMBER];
vector<int> edges[MAX_NUMBER];
int result = MAX_NUMBER;

void bfs(int idx);
int main() {
  set<int> root_candidate;
  for (int i=1;i<=MAX_NUMBER;i++)
    web[i] = i;
  for (int i=2;i<=MAX_NUMBER;i++) {
    if (web[i] == i) {
      for(int j=2;i*j<=MAX_NUMBER;j++) {
        web[i*j] = min(web[i*j], i);
      }
    }
  }

  int n;
  sci(n);
  for(int i=0;i<n;i++) {
    sci(data[i]);
    int a = data[i];
    vector<int> prime_factor;
    vector<int> real_factor;
    if (data_check[a]){
      result = min(result, 2);
    }
    data_check[a] = 1;
    while (a > 1) {
      prime_factor.push_back(web[a]);
      a = a / web[a];
    }

    for (int j = 1; j < prime_factor.size(); j++) {
      if (prime_factor[j-1] == prime_factor[j]) {
        prime_factor[j-1] = 0;
        prime_factor[j] = 0;
      }
    }


    for (int j = 0; j < prime_factor.size(); j++) {
      if (prime_factor[j] != 0) {
        real_factor.push_back(prime_factor[j]);
        root_candidate.insert(prime_factor[j]);
      }
    }

    if (real_factor.size() == 0) {
      result = 1;
    } else if (real_factor.size() == 2) {
      edges[real_factor[0]].push_back(real_factor[1]);
      edges[real_factor[1]].push_back(real_factor[0]);
    } else if (real_factor.size() == 1){
      edges[1].push_back(real_factor[0]);
      edges[real_factor[0]].push_back(1);
    }
  }

  for(int i=0;i<1000; i++){
    if (web[i] == i) {
      bfs(i);
    }
  }
  if (result == MAX_NUMBER) result = -1;
  printf("%d", result);

  return 0;
}
void bfs(int idx) {
  map<int, int> depth, parent;
  queue<int> q;
  q.push(idx);
  depth[idx] = 1;
  while(!q.empty()) {
    int from = q.front(); q.pop();
    for (const auto& edge: edges[from]) {
      const int& to = edge;
      if (to < idx) continue;
      if (to != parent[from]) {
        if (depth.find(to) != depth.end()) { // visited
          result = min (result, depth[from] + depth[to] - 1);
        } else {
          parent[to] = from;
          depth[to] = depth[from] + 1;
          q.push(to);
        }
      }
    }
  }
}
