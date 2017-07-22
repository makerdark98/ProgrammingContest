#include <iostream>

int main() {
    int N;
    for(int i=1;;i++){
        int sum=0, tmp;
        scanf("%d",&N);
        if(N==0){
            break;
        }
        while(N--){
            scanf("%d", &tmp);
            if(tmp) sum++;
            else sum--;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}