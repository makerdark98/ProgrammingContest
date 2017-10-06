#include <iostream>
using namespace std;

int main(){
    int n;
    int sum=0;
    scanf("%d",&n);
    while(n>0){
        sum+=n/5;
        n/=5;
    }
    printf("%d\n",sum);
    return 0;
}
