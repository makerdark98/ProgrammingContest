#include <iostream>
using namespace std;
int main(){
    int m[501][501]={{0}};
    int n,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int j=x1;j<x2;j++){
            for(int l=y1;l<y2;l++){
                if(m[j][l]) continue;
                m[j][l]=1;
                sum++;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
