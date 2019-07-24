#include <iostream>
#define sci(n) scanf("%d", &(n))
using namespace std;
bool chk() {
  int a;
  bool retval = true;
  for (int i=0;i<10;i++){
    sci(a);
    if((i % 5) + 1 != a) retval = false;
  }
  return retval;
}
int main () {
  int n;
  sci(n);
  for(int i=0;i<n;i++) {
    if (chk()) {
      printf("%d\n", i+1);
    }
  }
  return 0;
}
