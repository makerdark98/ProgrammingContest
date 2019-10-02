#include <iostream>
#include <cmath>
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
int main(){
  lld n;
  scl(n);
  lld result = 0;
  int i, j;

  for(i=1, j=0;i<=n;i+=j){
    j = ((n-1)/i)==0 ? 1 : ((n-1)%i)  / ((n-1)/i)+1;
    result += (1+(n-1)/i) * j;
  }

  printf("%lld", result);
  return 0;
}
