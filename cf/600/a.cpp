#include <iostream>
#include <vector>
using namespace std;
bool solve(vector<int>& a, vector<int>& b, int n);
int main () {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n;i ++) scanf("%d", &a[i]);
    for(int i = 0; i < n;i ++) scanf("%d", &b[i]);
    printf("%s\n", solve(a, b, n) ? "YES" : "NO");
  }
  return 0;
}
bool solve(vector<int>& a, vector<int>& b, int n) {
  int idx = 0;
  while (idx < n && a[idx] == b[idx]) idx ++;
  int diff = idx < n ? b[idx] - a[idx] : 0;
  if (diff < 0) return false;
  while (idx < n && a[idx] + diff == b[idx]) idx ++;
  while (idx < n && a[idx] == b[idx]) idx ++;
  return idx == n;
}
