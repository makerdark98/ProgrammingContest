#include <iostream>
using namespace std;

int main(){
    int n,sum =0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int c, k;
        scanf("%d %d", &c, &k);
        sum += c*k;
    }
    printf("%d\n",sum);
    return 0;
}
