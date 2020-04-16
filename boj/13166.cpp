#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define sci(n) scanf("%d", &(n))
struct relation {
  int s, f, c;
};

vector<relation> data;
vector<bool> suspect, friends;
int suspect_cnt;

int main () {
  int N;
  sci (N);
  int f, c;
  friends.assign(1000000, false);
  suspect.assign(200010, false);
  for (int s = 0; s < N; s++) {
    sci(f), sci(c);
    data.push_back({s, f, c});
    sci(f), sci(c);
    data.push_back({s, f, c});
  }
  
  sort(data.begin(), data.end(), [](const relation &a, const relation &b) -> bool {
    return a.c < b.c;
      });

  for (const auto& d : data) {
    if (!suspect[d.s] && !friends[d.f]) {
      suspect[d.s] = true;
      friends[d.f] = true;
      suspect_cnt ++;
    }
    if (suspect_cnt == N) {
      printf("%d\n", d.c);
      return 0;
    }
  }
  return 0;
}
