#include <iostream>
#include <string>
using namespace std;
using lld = long long;
#define sci(N) scanf("%d", &(N))
#define scl(N) scanf("%d", &(N))

int data[20];
int position[20];
string a[20];
lld dp[1 << 16][110];

lld gcd(lld a, lld b) {
  lld r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main () {
  int N, K;
  sci(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sci(K);

  for (int i = 0; i < N; i++) {
    data[i] = 0;
    for (auto& t: a[i]) {
      data[i] = ((data[i] * 10 % K) + t - '0') % K;
    }
    data[i] %= K;

    position[i] = 1;
    for (int j = 0; j < a[i].length(); j++) {
      position[i] *= 10;
      position[i] %= K;
    }
  }

  dp[0][0] = 1;

  for (int i = 0; i <= (1 << N) - 1; i ++) {
    for (int j = 0; j < N; j ++) {
      if ((i & (1 << j)) == 0) {
        for (int q = 0; q < K; q ++) {
          dp[i | (1 << j)][(q * position[j] + data[j]) % K] += dp[i][q];
        }
      }
    }
  }
  lld p = 1;

  for (int i = 1; i <= N; i++) p *= i;
  lld g = gcd(dp[(1 << N) - 1][0], p);

  printf("%lld/%lld", dp[(1 << N) - 1][0] / g, p / g);

  return 0;
}
