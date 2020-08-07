#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define sci(N) scanf("%d", &(N))
int N;

int main () {
  sci(N);
  queue<int> q;
  while (N--) {
    char op[10];
    scanf(" %s", op);
    if (strcmp(op, "push") == 0) {
      int X;
      sci(X);
      q.push(X);
    } else if (strcmp(op, "pop") == 0) {
      printf("%d\n", q.empty() ? -1 : q.front());
      if (!q.empty()) q.pop();
    } else if (strcmp(op, "size") == 0) {
      printf("%d\n", (int)q.size());
    } else if (strcmp(op, "empty") == 0) {
      printf("%d\n", q.empty() ? 1 : 0);
    } else if (strcmp(op, "front") == 0) {
      printf("%d\n", q.empty() ? -1 : q.front());
    } else if (strcmp(op, "back") == 0) {
      printf("%d\n", q.empty() ? -1 : q.back());
    }
  }
  return 0;
}
