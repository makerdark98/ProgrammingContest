#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 3000007
#define F first
#define S second

using pii = pair<int, int>;
using piii = pair<pair<int, int>, int>;
using ll = long long;
int real_n, real_m;
int n, m, k;
pii sword[MAX_SIZE], shield[MAX_SIZE];
pii real_sword[MAX_SIZE], real_shield[MAX_SIZE];
piii monster[MAX_SIZE];
int updated_log[MAX_SIZE*4];
int seg_tree[MAX_SIZE*4];
int base;
void refine();
void add_range(int s, int e, int value);
ll max_query(int idx, int value);
int findSword(int x);

int main () {
  scanf("%d%d%d",&n, &m, &k);
  for(int i=0;i<n;i++) {
    scanf("%d%d", &sword[i].first, &sword[i].second);
  }
  for(int i=0;i<m;i++) {
    scanf("%d%d", &shield[i].first, &shield[i].second);
  }
  for(int i=0;i<k;i++) {
    scanf("%d%d%d", &monster[i].first.first, &monster[i].first.second, &monster[i].second);
  }
  sort(sword, sword+n);
  sort(shield, shield+m);
  refine();
  sort(monster, monster+k);

  for (base = 1; base < MAX_SIZE; base <<= 1)
    ;

  long long result = 0;
  for (int i=0;i<k;i++) {
    add_range(monster[i].first.second, monster[k].first.second, monster[i].second);
    result = max(result, max_query(0, monster[i].first.second) - findSword(monster[i].first.first));
  }
  printf("%lld", result);

  return 0;
}

void refine(){
  real_sword[0] = sword[0];
  real_shield[0] = shield[0];
  int i;
  for (i=1, real_n=0;i<n;i++) {
    if (real_sword[real_n].first == sword[i].first && real_sword[real_n].second > sword[i].second) {
      real_sword[real_n] = sword[i];
    } else {
      real_sword[real_n] = shield[i];
    }
  }
  real_n++;
  for (i=1, real_m=0;i<m;i++) {
    if (real_shield[real_m].first == shield[i].first && real_shield[real_m].second > shield[i].second) {
      real_shield[real_m] = shield[i];
    } else {
      real_shield[++real_m] = shield[i];
    }
  }
  real_m++;

  add_range(0, real_shield[real_m-1].first, -real_shield[real_m-1].second);
  for (i=real_m-2;i>=0;i--) {
    add_range(0, real_shield[i+1].first, real_shield[i+1].second);
    add_range(0, real_shield[i].first, -real_shield[i].second);
  }
}

void add_range_internal(int s, int e, int value) {
  static long long timestamp = 2;
  while (s < e) {
    if (s % 2 == 1) updated_log[s++] += value;
    if (e % 2 == 0) updated_log[e--] += value;
    s <<= 1; e <<= 1;
    if (s == e) updated_log[s] += value;
  }
  timestamp ++;
}
void add_range(int s, int e, int value){
  add_range_internal(base + s, base + e, value);
}

ll max_query_internal(int s, int e) {
  int c = 1;
  ll retval = - MAX_SIZE;
  while (s < e) {
  }
}
long long max_query(int s, int e){
  return max_query_internal(base + s, base + e);
}
int findSword(int x){
  int s = 0, e = real_n-1;
  while (s < e) {
    int mid = (s + e) / 2;
    if (real_sword[m].first > x) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }
  return e;
}
