#include <iostream>
#include <map>
#include <math.h>
#define sci(n) scanf("%d", &(n))
using namespace std;
int getValue(int c, int r) {
    int res;
    if (c >= 0 && c * -1 <= r && r <= c)
        res = pow(c*2+1, 2) - (c-r);
    else if (c<0 && c<=r && r<=abs(c))
        res = pow(c*2, 2)-(abs(c)-1) - r;
    else if (r>=c && r>-1*c)
        res = pow(r*2-1, 2) + (r-c);
    else
        res = pow(r*2, 2) + (c-r+1);
    return res;
}
int main() {
    int r1, r2, c1, c2;
    map<int, map<int, string> > ans;
    int maxSize = 0;
    sci(r1), sci(c1), sci(r2), sci(c2);
    for(int i=r1;i<=r2;i++) {
        for(int j=c1;j<=c2;j++) {
            ans[i][j] = to_string(getValue(i, j));
            maxSize = max(maxSize, (int)ans[i][j].size());
        }
    }
    for(int i=r1;i<=r2;i++) {
        for(int j=c1;j<=c2;j++) {
            cout << string((j==c1 ? 0 : 1 )+maxSize-ans[i][j].size(), ' ') << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
