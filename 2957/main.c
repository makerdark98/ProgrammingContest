#include <stdio.h>
int Tree[300001];
int input[300001];
int idx;


void insert(int x, int n);
int main() {
    int T, X;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        printf("%d", idx);
        scanf("%d", &X);
        insert(X,1);
    }

    return 0;
}

void insert(int x, int n){
    idx++;
    if(x<Tree[n]){
        if(Tree[n*2]==0){
            Tree[n*2]=x;
        }
        else{
            insert(x,n*2);
        }
    }
    else{
        if(Tree[n*2+1]==0){
            Tree[n*2+1]=x;
        }
        else{
            insert(x,n*2+1);
        }
    }
}