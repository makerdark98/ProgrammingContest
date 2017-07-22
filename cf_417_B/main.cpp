#include <stdio.h>

int n,m;
int building[16][115];
int time;
void move(int x, int y, int move_count);
int main() {
    char input;
    scanf("%d %d", &n, &m);
    for(int i=n-1;i>-1;i--){
        for(int j=0;j<m+2;j++){
            scanf(" %c", &input);
            if(input=='1') building[i][j]=1;
        }
    }
    move(0,0,0);
    printf("%d",time);
    return 0;
}

void move(int x, int y, int move_count){
    if(y==n) return;
    if(building[y][x]==1){
        time+=move_count;
        move_count=0;
    }

    if(y%2==0){
        if(x==m+1){
            move(x, y+1, move_count+1);
        }
        else{
            move(x+1, y, move_count+1);
        }
    }
    else{
        if(x==0){
            move(x, y+1, move_count+1);
        }
        else{
            move(x-1, y, move_count+1);
        }
    }
    return;
}