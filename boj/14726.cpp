#include <iostream>
using namespace std;

int main(){
    int A[16];
    int n;
    scanf("%d",&n);
    int sum;
    while(n--){
        sum =0;
        for(int i=0;i<16;i++){
            scanf("%1d",&A[i]);
        }
        for(int i=0;i<16;i+=2){
            A[i] *=2;
            if(A[i]>=10){
                A[i] = A[i]/10 + A[i]%10;
            }
        }
        for(int i=0;i<16;i++){
            sum+=A[i];
        }
        if(sum%10==0) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
