#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    vector<bool> number;
    int M, N;
    scanf("%d %d",&M,&N);
    number.assign(N+1,true);
    for(int i=2;i<N+1;i++){
        if(number[i]){
            for(int k=2;i*k<N+1;k++){
                number[i*k]=false;
            }
        }
    }
    number[1]=false;
    for(int i=M;i<N+1;i++){
        if(number[i]) printf("%d\n", i);
    }
    return 0;
}
