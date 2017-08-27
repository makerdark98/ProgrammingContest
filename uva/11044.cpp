#include <iostream>
#include <math.h>
int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        printf("%d\n", int(ceil(double(n-2)/3)*ceil(double(m-2)/3)));
    }
    return 0;
}