#include <iostream>

int Map[130][130];
int Divide(int xs,int xe,int ys,int ye, int& bcount,int& wcount){
    if(xs>=xe){
        if(Map[xs][ys]) {
            bcount =1;
            wcount = 0;
        }
        else {
            bcount = 0;
            wcount =1;
        }
        return Map[xs][ys];
    }
    int n1,n2,n3,n4;
    int bc1,bc2,bc3,bc4;
    int wc1,wc2,wc3,wc4;
    n1=Divide(xs,xs+(xe-xs)/2,ys,ys+(ye-ys)/2,bc1,wc1);
    n2=Divide(xs+(xe-xs)/2+1, xe, ys,ys+(ye-ys)/2,bc2,wc2);
    n3=Divide(xs+(xe-xs)/2+1,xe,ys+(ye-ys)/2+1,ye,bc3,wc3);
    n4=Divide(xs,xs+(xe-xs)/2,ys+(ye-ys)/2+1,ye,bc4,wc4);
    bcount=bc1+bc2+bc3+bc4;
    wcount=wc1+wc2+wc3+wc4;
    if(n1==n2&&n1==n3&&n1==n4) {
        if(Map[xs][ys]) {
            bcount =1;
            wcount = 0;
        }
        else {
            bcount = 0;
            wcount =1;
        }        return Map[xs][ys];
    }
    return -1;
}

int main() {
    int N, bcount,wcount;
    scanf("%d",&N);
    for(int i = 0; i<N;i++){
        for(int j =0;j<N;j++){
            scanf("%d",&Map[i][j]);
        }
    }
    Divide(0,N-1,0,N-1,bcount,wcount);
    printf("%d\n%d",wcount,bcount);

    return 0;
}