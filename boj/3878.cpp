#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define sci(N) scanf("%d", &(N))
#define scl(N) scanf("%lld", &(N))
#define x first
#define y second
#define SIZE 1000
#define INF 987654321
using lld = long long;
using pii = pair<lld, lld>;
lld ccw(const pii& a, const pii& b, const pii& c) {
  lld tmp = a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
  if (tmp > 0) return 1;
  if (tmp < 0) return -1;
  return 0;
}
bool isIntersect(pii p1, pii p2, pii q1, pii q2) {
  lld pq = ccw (p1, p2, q1) * ccw(p1, p2, q2);
  lld qp = ccw (q1, q2, p1) * ccw(q1, q2, p2);
  if (p1 > p2) swap(p1, p2);
  if (q1 > q2) swap(q1, q2);
  return (!pq && !qp) ? q1 <= p2 && p1 <= q2 : pq <= 0 && qp <= 0;
}
void convex(const vector<pii> p, vector<pii>& retval) {
  int cur = 1, sz, n = p.size();
  if (n <= 2) {
    for (int i = 0; i < p.size(); ++ i)
      retval.push_back(p[i]);
    return;
  }
  vector<pii> up, down;
  up.push_back(p[0]);
  while (cur < n) {
    sz = up.size();
    if (sz < 2 || ccw(up[sz - 2], up[sz - 1], p[cur]) < 0) up.push_back(p[cur ++]);
    else up.pop_back();
  }
  cur = 1;
  while (cur < n) {
    sz = down.size();
    if (sz < 2 || ccw(down[sz - 2], down[sz - 1], p[cur]) > 0) down.push_back(p[cur ++]);
    else down.pop_back();
  }
  retval.resize(up.size() + down.size() - 2);
  copy(up.begin(), up.end(), retval.begin());
  copy(down.rbegin() + 1, down.rend() - 1, retval.begin() + up.size());
}

int main () {
  int T;
  sci(T);
  while (T --) {
    int N, M;
    sci(N), sci(M);
    vector<pii> p1(N), p2(M), con1, con2;
    for (int i = 0; i < N; ++ i) {
      scl(p1[i].x), scl(p1[i].y);
    }
    for (int i = 0; i < M; ++ i) {
      scl(p2[i].x), scl(p2[i].y);
    }


    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    convex(p1, con1);
    convex(p2, con2);
    /*
    if (con1.size() == 1 && con2.size() == 1) { printf("YES\n"); continue; }
    else if (con1.size() == 1 && con2.size() == 2) {
      printf("%s\n", (con2[0].y - con1[0].y) * (con2[1].x - con1[0].x) == (con2[1].y - con1[0].y) * (con2[0].x - con1[0].x) ?
          "NO" : "YES");
      continue;
    } else if (con1.size() == 2 && con2.size() == 1) {
      printf("%s\n", (con1[0].y - con2[0].y) * (con1[1].x - con2[0].x) == (con1[1].y - con2[0].y) * (con1[0].x - con2[0].x) ?
          "NO" : "YES");
      continue;
    } else if (con1.size() == 2 && con2.size() == 2) {
      printf("%s\n", isIntersect(con1[0], con1[1], con2[0], con2[1]) ? "NO" : "YES");
      continue;
    }
    */

    int length1 = con1.size(), length2 = con2.size();
    bool result = false;
    for (int i = 0; i < con1.size(); ++ i) {
      if (result) break;
      for (int j = 0; j < con2.size(); ++ j) {
        if (isIntersect(con2[j], con2[(j + 1) % length2], con1[i], con1[(i + 1) % length1])) {
          result = true;
          break;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < length1; ++ i) {
      if (isIntersect(con2[0], {-INF, con2[0].y}, con1[i], con1[(i + 1) % length1])) cnt ++;
    }
    if (cnt % 2 != 0) result = true;
    cnt = 0;
    for (int i = 0; i < length2; ++ i) {
      if (isIntersect(con1[0], {-INF, con1[0].y}, con2[i], con2[(i + 1) % length2])) cnt ++;
    }
    if (cnt % 2 != 0) result = true;
    printf("%s\n", result ? "NO" : "YES");
  }
  return 0;
}
