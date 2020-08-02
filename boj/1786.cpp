#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define SIZE 1000010

char T[SIZE], P[SIZE];
void kmp(char* h, int n, char* p, int* pi, int* retval) {
    int matched = 0;
    for(int i = 0; i < n; i ++) {
        while (matched > 0 && h[i] != p[matched])
            matched = pi[matched - 1];
        if (h[i] == p[matched]) {
            matched ++;
            retval[i] = matched;
        }
    }
}
int PI[SIZE], result[SIZE];
int main () {
    cin.getline(T, SIZE);
    cin.getline(P, SIZE);
    int n = strlen(T), m = strlen(P);
    
    kmp(P+1, m - 1, P, PI, PI + 1);
    kmp(T, n, P, PI, result);
    int c = 0;
    for (int i = 0; i < n; i ++)
        if (result[i] == m) c++;
    printf("%d\n", c);
    for (int i = 0; i < n; i ++) {
        if (result[i] == m) printf("%d ", i - m + 2);
    }
    
    return 0;
}
