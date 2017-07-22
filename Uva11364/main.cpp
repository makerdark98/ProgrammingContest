#include <iostream>
int main() {
    int t, n, min, max;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        min = 99999;
        max = 0;
        while(n--){
            int tmp;
            scanf("%d", &tmp);
            max = max<tmp ? tmp : max;
            min = min>tmp ? tmp : min;
        }
        printf("%d\n", (max-min)*2);
    }
    return 0;
}