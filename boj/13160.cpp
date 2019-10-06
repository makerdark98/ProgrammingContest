#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define sci(n) scanf("%d", &(n))
int main() {
  int N, tmp;
  sci(N);
  vector<pair<int, int> > data(2*N);
  for(int i=0;i<N;i++) {
    sci(tmp);
    data[2*i].first = tmp;
    data[2*i].second = i+1;
    sci(tmp);
    data[2*i+1].first = tmp;
    data[2*i+1].second = -i-1;
  }
  sort(data.begin(), data.end(), [](const pair<int, int>& a, const pair<int, int>& b)-> bool {
      return a.first == b.first ? a.second > b.second : a.first < b.first;
      });
  int now = 0;
  int result = 0;
  int idx = 0;
  for (int i=0;i<2*N;i++) {
    if (data[i].second > 0) now ++;
    else now --;

    if (result < now) {
      idx = i;
      result = now;
    }
  }

  set<int> answersheet;
  for (int i=0;i<=idx;i++) {
    if (data[i].second > 0) answersheet.insert(data[i].second);
    else answersheet.erase(-data[i].second);
  }

  printf("%d\n", result);
  for (auto &c: answersheet) {
    printf("%d ", c);
  }
  return 0;
}
