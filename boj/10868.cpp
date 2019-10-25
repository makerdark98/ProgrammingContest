#include <iostream>
#include <queue>
#define MAX 1e9+7L
#define sci(n) scanf("%d", &(n))
#define scl(n) scanf("%d", &(n))
using namespace std;
using lld = int;
int N, M, s, e, base;
void min_build();
lld mintree[400400];
lld minquery(int s, int e);
int main() {
  sci(N), sci(M);
  for(base = 1; base < N; base <<= 1) 
    ;
  for(int i=0;i<N;i++) scl(mintree[base + i]);
  min_build();

  for(int i=0;i<M;i++) {
    sci(s), sci(e);
    printf("%d\n",
        minquery(base + s - 1, base + e -1));
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
