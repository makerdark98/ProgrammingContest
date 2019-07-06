#include <iostream>
#include <cmath>
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
lld solve(lld n){
  lld result = n;
  for(lld i=n-1, q = 1;i>1;){
    lld nexti = (n-1)/q;
    result += q * (i-nexti);
    i = nexti;
    q++;
  }
  return result;
}
int main(){
  lld n;
  scl(n);
  printf("%lld", solve(n)+1);
  return 0;
}
