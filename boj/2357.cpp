#include <iostream>
#include <queue>
#define SIZE 100100
#define MAX 1e9+7LL
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%lld", &(n))
using namespace std;
using lld = long long;
int N, M, s, e, base;
void max_build();
void min_build();
lld data[SIZE];
lld maxtree[SIZE*4], mintree[SIZE*4];
lld minquery(int s, int e);
lld maxquery(int s, int e);
int main() {
  sci(N), sci(M);
  for(int i=0;i<N;i++) scl(data[i]);
  for(base = 1; base < N; base <<= 1) 
    ;
  for(int i=0;i<N;i++) {
    maxtree[base + i] = data[i];
    mintree[base + i] = data[i];
  }
  max_build();
  min_build();

  for(int i=0;i<M;i++) {
    sci(s), sci(e);
    printf("%lld %lld\n", minquery(base + s - 1, base + e -1), maxquery(base + s - 1, base + e - 1));
  }
  return 0;
}
lld minquery(int s, int e) {
  int result, rs = MAX, re = MAX;
  if (s == e) return mintree[s];
  else if (s > e) return MAX;
  if (s % 2 == 1) rs = mintree[s++];
  if (e % 2 == 0) re = mintree[e--];

  result = minquery(s >> 1, e >> 1);
  result = result < rs ? result : rs;
  result = result < re ? result : re;

  return result;
}
lld maxquery(int s, int e) {
  int result, rs = -MAX, re = -MAX;
  if (s == e) return maxtree[s];
  else if (s > e) return -MAX;
  if (s % 2 == 1) rs = maxtree[s++];
  if (e % 2 == 0) re = maxtree[e--];

  result = maxquery(s >> 1, e >> 1);
  result = result > rs ? result : rs;
  result = result > re ? result : re;
  return result;
}

void max_build() {
  for (int nowbase = (base >> 1); nowbase >= 1; nowbase >>= 1) {
    for (int i = nowbase; i < nowbase << 1; i ++) {
      maxtree[i] = maxtree[i << 1] > maxtree[(i << 1) + 1] ?  maxtree[i << 1] : maxtree[(i << 1) + 1];
    }
  }
}
void min_build() {
  for (int nowbase = (base >> 1); nowbase >= 1; nowbase >>= 1) {
    for (int i = nowbase; i < nowbase << 1; i ++) {
      mintree[i] = mintree[i << 1] < mintree[(i << 1) + 1] ?  mintree[i << 1] : mintree[(i << 1) + 1];
    }
  }
}
/*
   10 4
   75
   30
   100
   38
   50
   51
   52
   20
   81
   5
   1 10
   3 5
   6 9
   8 10
   */
