#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#define MAX 1e12
using namespace std;
using lld = long long;
const lld MIN = numeric_limits<lld>::min();
lld square_distance (const pair<lld, lld>& a, const pair<lld, lld>& b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main () {
  int n;
  scanf("%d", &n);
  vector<pair<lld, lld>> points(n);
  for (int i=0;i<n;i++) {
    scanf("%lld%lld", &points[i].first, &points[i].second);
  }
  // sort by y
  sort(points.begin(), points.end(), [](pair<lld, lld>& a, pair<lld, lld>& b)->bool {
      return a.second == b.second ? a.first < b.first : a.second < b.second;
      });
  set<pair<lld, lld>> s; // sort by x
  int front = 0;
  s.insert(points[0]);
  s.insert(points[1]);
  lld d = square_distance (points[0], points[1]);
  for (int i = 2; i < n; i++) {
    while (front < i) {
      if ((points[front].second - points[i].second) * (points[front].second - points[i].second) > d) {
        s.erase(points[front]);
        front ++;
      }
      else break;
    }
    auto it = s.lower_bound({points[i].first-sqrt(d), MIN});
    while (it != s.end() && it->second < points[i].second + sqrt(d)) {
      d = min (d, square_distance(*it, points[i]));
      it ++;
    }
    s.insert(points[i]);
  }
  printf("%lld", d);
  return 0;
}
