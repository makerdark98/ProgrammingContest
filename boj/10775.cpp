#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
int find(int idx){
  if (parent[idx] == idx) return parent[idx];
  return parent[idx] = find(parent[idx]);
}
int main () {
  int P, G, g;
  scanf("%d", &G);
  parent.assign(G+1, 0);
  for(int i=0;i<G+1;i++) {
    parent[i] = i;
  }

  scanf("%d", &P);
  int ans = 0;
  for (int i=0;i<P;i++) {
    scanf("%d", &g);
    int p = find(g);
    if (p == 0)
      break;
    parent[p]= p-1;
    ans ++;
  }
  printf("%d", ans);
  return 0;
}
