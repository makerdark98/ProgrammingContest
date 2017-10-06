#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    double A[8];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<7;i++){
        scanf("%lf",&A[i]);
    }
    sort(A,A+7);
    A[7]=100;
    for(;i<n;i++){
        double tmp;
        scanf("%lf",&tmp);
        if(A[6]>=tmp){ 
            A[7] = tmp;
            sort(A,A+8);
        }
    }
    for(i=0;i<7;i++){
        printf("%.3lf\n",A[i]);
    }
    return 0;
}
