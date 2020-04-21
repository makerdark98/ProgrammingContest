#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using lld = long long;
int main () {
  int n;
  while (true) {
    scanf("%d", &n);
    if (n == 0) return 0;
    vector<lld> h(n+2);
    for (int i=1;i<=n;i++) {
      scanf("%lld", &h[i]);
    }

    stack<lld> s;
    h[0] = 0;
    h[n+1] = 0;
    s.push(0);
    lld result = 0;
    for (int i=1;i<=n+1;i++) {
      if (h[s.top()] > h[i]){
        while (!s.empty() && h[s.top()] > h[i]) {
          int height = h[s.top()];
          s.pop();
          result = max (result, height * (i-s.top() - 1));
        }
      }
      s.push(i);
    }
    printf("%lld\n", result);
  }
  return 0;
}
