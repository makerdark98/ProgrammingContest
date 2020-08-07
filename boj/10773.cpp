#include <iostream>
#include <stack>
using namespace std;
#define sci(N) scanf("%d", &(N))
int K, a;
int main () {
  sci(K);
  stack<int> s;
  for (int i = 0; i < K; i ++){
    sci(a);
    if (a == 0) s.pop();
    else s.push(a);
  }

  long long sum = 0;
  while(!s.empty()) {
    sum += s.top();
    s.pop();
  }
  printf("%lld", sum);
  return 0;
}
