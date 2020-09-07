/**
 * Copyright [2020] <makerdark98@gmail.com>"
 */
#include <iostream>
using std::cout;
int main() {
    int T;
    scanf("%d", &T);
    int64_t fibo[200];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 41; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n == 0)
          cout << "1 0\n";
        else if (n == 1)
          cout << "0 1\n";
        else
          cout << fibo[n-1] << " " << fibo[n] << "\n";
    }
    return 0;
}
