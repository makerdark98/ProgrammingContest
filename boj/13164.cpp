#include <iostream>
#include <vector>
#include <algorithm>
#define sci(n) scanf("%d", &(n))
using namespace std;

using vi = vector<int>;
int main() {
  int n, k;
  sci(n), sci(k);
  int before = 0, now;
  vi diff(n+1);
  for(int i=1;i<=n;i++) {
    sci(now);
    diff[i] = now - before;
    before = now;
  }
  diff[1] = 0;
  sort(diff.begin(), diff.end(), greater<int>());
  int result = 0;
  for(int i=k-1;i<n;i++)
    result += diff[i];
  printf("%d", result);
  return 0;
}
