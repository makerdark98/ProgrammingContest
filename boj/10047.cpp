#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int N, K, count=0;
    vector<int> coin;
    scanf("%d %d",&N,&K);
    coin.assign(N,0);
    for(int i =0;i<N;i++){
        int tmp;
        scanf("%d",&tmp);
        coin[i]=tmp;
    }
    while(N--){
        count+=K/coin[N];
        K%=coin[N];
    }
    printf("%d\n", count);
    return 0;
}