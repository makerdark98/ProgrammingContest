#include <iostream>
#include <vector>
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))

using namespace std;
using lld = long long;
using vi = vector<lld>;

int base, N;
vi data;

int main() {
  sci(N);
  data.resize(N);
  for(int i=0;i<N;i++) {
    scl(data[i]);
  }

  for (base = 1; base < N; base <<= 1)
    ;
  
  return 0;
}
