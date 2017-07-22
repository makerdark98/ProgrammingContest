#include <stdio.h>

int main() {
    int T;
    int x1, y1, r1, x2, y2, r2, i, out, d1, d2, d3;
    scanf("%d", &T);
    for(i=0;i<T;i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        d1 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        d2 = (r1-r2)*(r1-r2);
        d3 = (r1+r2)*(r1+r2);
        if(x1==x2&&y1==y2&&r1==r2) out = -1;
        else if(d1==d2||d1==d3){
            out = 1;
        }
        else if(d1>d2&&d1<d3){
            out = 2;
        }
        else out = 0;
        printf("%d\n", out);
    }
    return 0;
}