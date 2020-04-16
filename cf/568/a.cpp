#include <iostream>
#include <algorithm>
using namespace std;
#define sci(n) scanf("%d", &(n))
int main() {
    int d;
    int data[3];
    for(int i=0;i<3;i++) sci(data[i]);
    sci(d);
    sort(data, data+3);
    int result = max(0, d-(data[1] - data[0])) + max(0, d- (data[2]-data[1]));
    printf("%d", result);
    return 0;
}
