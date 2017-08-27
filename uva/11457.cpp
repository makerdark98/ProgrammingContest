#include <iostream>

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n", abs((315*n+7492*5-498))%100/10);
    }
    return 0;
}