#include <iostream>
#include <stdio.h>
using namespace std;

int Left(int x){
    return x==0? 3 : x-1;
}
int Right(int x){
    return x==3? 0 : x+1;
}

int main() {
    int Road[4][3];
    int Light[4];
    int output = 0;
    for(int i =0;i<4;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &Road[i][j]);
        }
        scanf("%d", &Light[i]);
    }
    for(int i=0;i<4;i++){
        if(Light[i]){
            if(Road[Left(i)][2] || Road[Right(i)][0]){
                output = 1;
            }
        }
    }

    if(output){
        printf("YES\n");
    }
    else printf("NO\n");

    return 0;
}