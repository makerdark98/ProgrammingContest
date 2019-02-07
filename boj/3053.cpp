#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#define sci(n) scanf("%d", &(n))
using namespace std;
double getU(int r){ return M_PI*r*r;}
double getT(int r){ return 2*r*r;}
int main() {
    int R;
    sci(R);
    printf("%lf\n", getU(R));
    printf("%lf\n", getT(R));
    return 0;
}
