#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
using namespace std;
using lld = long long;

int main() {
  int n, m;
  sci(n), sci(m);
  priority_queue<int, vector<int>, greater<int> > q;
  for(int i=0;i<n;i++){
    int t;
    sci(t);
    q.push(t);
  }
  for(int i=0;i<m;i++){
    int f = q.top(); q.pop();
    int s = q.top(); q.pop();
    q.push(f+s); q.push(f+s);
  }
  lld result = 0;
  while (!q.empty()) {
    result += q.top(); q.pop();
  }
  printf("%lld", result);
  return 0;
}
