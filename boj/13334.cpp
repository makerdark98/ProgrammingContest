#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using lld = long long;
using ii = pair<lld, lld>;
using vii = vector<ii>;
using vi = vector<lld>;
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))

int main () {
  lld n;
  scl (n);
  vii data(n);
  for (int i=0;i<n;i++) {
    lld a, b;
    scl(a), scl(b);
    data[i] = {min(a, b), max(a, b)};
  }

  sort(data.begin(), data.end(), [](const ii& a, const ii& b)-> bool {
    return a.second == b.second ? a.first < b.first : a.second < b.second; });
  lld d;
  scl(d);

  lld result = 0;
  priority_queue<lld> q;
  for (lld i=0;i<n;i++){
    q.push(-data[i].first);
    while(!q.empty() && -q.top() + d< data[i].second) q.pop();
    result = result > q.size() ? result : q.size();
  }

  printf("%lld", result);

  return 0;
}
