#include <iostream>
#include <vector>
#include <set>
using namespace std;
int solve (vector<int>& a, int n);
int main () {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
  printf("%d", solve(a, n));
  return 0;
}

int solve (vector<int>& a, int n) {
  int retval = 1;

  set<int> day;
  for(int i=0;i<n;i++) {
    if(a[i] > 0) {
      if(day.insert)
    }
  }
  return retval;
}
