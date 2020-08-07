#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
#define sci(N) scanf("%d", &(N))
#define SIZE 1010
int K, a;
char S[SIZE];
int main () {
  while (true) {
    bool result = true;
    cin.getline(S, SIZE);
    if (strcmp(S, ".") == 0) break;

    stack<int> s;
    int n = strlen (S);
    for (int i = 0; i < n; i ++) {
      if (S[i] == '(') {
        s.push(1);
      } else if (S[i] == ')') {
        if (s.empty() || s.top() != 1) {
          result = false;
          break;
        }
        s.pop();
      } else if (S[i] == '[') {
        s.push(2);
      } else if (S[i] == ']') {
        if (s.empty() || s.top() != 2) {
          result = false;
          break;
        }
        s.pop();
      }
    }
    if (result && s.empty()) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
